// Copyright(C) 2014 kittikun
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// This work is compatible with the Dominion Rules role-playing system.To learn more about
// Dominion Rules, visit the Dominion Rules web site at <http://www.dominionrules.org>

#include "character_utility_impl.h"

#include <numeric>

#include "character_impl.h"
#include "database_impl.h"
#include "dice_impl.h"
#include "style_impl.h"
#include "classid_utility.h"
#include "../dice.h"
#include "../character/style.h"

namespace Dominion
{
    CharacterUtilityImpl::CharacterUtilityImpl(std::shared_ptr<DatabaseImpl> db) :
        db_{db},
        race_{RaceCount}
    {}

    CharacterUtilityImpl::~CharacterUtilityImpl()
    {}

    std::shared_ptr<const AttributePointsRemainder> CharacterUtilityImpl::attributesRoll(const std::shared_ptr<Dice>& dice)
    {
        std::array < uint_fast8_t, 3 >  res;

        for (size_t i = 0; i < res.size(); ++i)
            res[i] = dice->Roll();

        const uint_fast8_t sum = std::accumulate(std::begin(res), std::end(res), uint_fast8_t(0));

        aPtRemain_ = std::make_shared<const AttributePointsRemainder>(std::make_tuple(sum / 3, sum % 3));

        return aPtRemain_;
    }

    std::shared_ptr<CharacterImpl> CharacterUtilityImpl::MakeCharacter() const
    {
        if (Validate() == CharacterValidationResult::Valid) {
            uint_fast32_t id = ClassIDUtility<CharacterImpl>::next();
            std::shared_ptr<CharacterImpl> character = std::make_shared<CharacterImpl>(id);

            character->race_ = race_;
            character->style_ = style_;
            SetPerks(character);

            return character;
        }

        return std::shared_ptr<CharacterImpl>();
    }

    void CharacterUtilityImpl::SetPerks(const std::shared_ptr<CharacterImpl>& character) const
    {
        boost::format fmt = boost::format("select id from perk where %1% and roll=%2%") % RaceToPerkQuery() % (uint_fast32_t)perkRoll_;
        std::string query = boost::str(fmt);
        character->perks_.push_back(db_->Get<PerkImpl>(ClassID_Perk + db_->GetIntValue(query)));

        // (DR3.1.1 p30, 4-6 STEP TWO: THE CHARACTER GENERATION TABLE)
        // If you had only 5 Attribute Points or less to divide between your six Attributes
        // in Step Three, your character is automatically entitled to Favourable Rounding.
        if (std::get<0>(*aPtRemain_) <= 5) {
            fmt = boost::format("select id from perk where %1% and roll=1") % RaceToPerkQuery();
            query = boost::str(fmt);
            character->perks_.push_back(db_->Get<PerkImpl>(ClassID_Perk + db_->GetIntValue(query)));
        }
    }

    CharacterValidationResult CharacterUtilityImpl::Validate() const
    {
        if ((race_ < 0) || (race_ >= RaceCount))
            return CharacterValidationResult::InvalidRace;

        if (!style_)
            return CharacterValidationResult::MissingStyle;

        if ((perkRoll_ == 0) || (perkRoll_ > 12))
            return CharacterValidationResult::InvalidPerk;

        if (!aPtRemain_)
            return CharacterValidationResult::MissingAttributes;

        // (DR3.1.1 p30, 4-6 STEP TWO: THE CHARACTER GENERATION TABLE)
        // If you had only 5 Attribute Points or less to divide between your six Attributes (...)
        // If you are automatically entitled to Favourable Rounding, but your character already
        // got Favourable Rounding from the Character Generation Table, go back and reroll on that table.
        if ((perkRoll_ == 1) && (std::get<0>(*aPtRemain_) <= 5))
            return CharacterValidationResult::RerollPerk;

        uint_fast8_t sum = std::accumulate(attributes_.begin(), attributes_.end(), (uint_fast8_t)0);
        uint_fast8_t expected = 6 + std::get<0>(*aPtRemain_);
        uint_fast8_t max = 6 + 12;

        if ((sum > max) || (sum < expected) || (sum > expected)) {
            return CharacterValidationResult::InvalidAttributes;
        }

        return CharacterValidationResult::Valid;
    }

    std::string CharacterUtilityImpl::RaceToPerkQuery() const
    {
        switch (race_) {
        case RaceBeast:
            return "isBeast";

        case RaceDwarf:
            return "isDwarf";

        case RaceElf:
            return "isElf";

        case RaceHalfling:
            return "isHalfling";

        case RaceHuman:
            return "isHuman";

        case RaceHumanoid:
            return "isHumanoid";

        default:
            throw std::out_of_range("race value");
        }

        //return std::string();
    }
} // namespace Dominion
