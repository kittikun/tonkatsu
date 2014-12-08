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

#include "character_impl.h"

#include "database_impl.h"
#include "perk_impl.h"

namespace Dominion
{
    CharacterImpl::CharacterImpl(const uint_fast32_t id) :
        Data{id},
        race_{RaceCount},
        // (DR3.1.1 p31, 4-7 STEP FIVE: DETERMINE YOUR ADVANCEMENT POINTS)
        // All starting characters are given 45 Advancement
        // Points(APs) to spend as you see fit.Some characters
        // start with more that 45 APs.
        ap_{45}
    {}

    const std::vector<std::shared_ptr<PerkImpl>>& CharacterImpl::perks() const
    {
        return perks_;
    }

    //void CharacterImpl::perk(uint_fast8_t roll)
    //{
    //    boost::format fmt = boost::format("select id from perk where %1% and roll=%2%") % RaceToPerkQuery() % (uint_fast32_t)roll;
    //    std::string query = boost::str(fmt);
    //    std::shared_ptr<DatabaseImpl> db = db_.lock();
    //    uint_fast32_t id = ClassID_Perk + db->GetIntValue(query);

    //    if (perks_.size() > 0)
    //        perks_[0] = id;
    //    else
    //        perks_.push_back(id);
    //}

    std::string CharacterImpl::RaceToPerkQuery()
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
