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

#include "character.h"

#include <boost/format.hpp>

#include "perk.h"
#include "style.h"
#include "../impl/character_impl.h"
#include "../impl/style_impl.h"

namespace Dominion
{
    Character::Character(const std::shared_ptr<CharacterImpl>& impl) :
        impl_(impl)
    {}

    Character::~Character()
    {}

    std::shared_ptr<Perk> Character::perk() const
    {
        return std::make_shared<Perk>(impl_->perk_);
    }

    void Character::perk(uint8_t roll)
    {
        // We are using a 12 sided dice to play
        if ((roll == 0) || (roll > 12))
            throw std::invalid_argument("Trying to set perk with roll outside of 12 sided dice range");

        impl_->set_perk(roll);
    }

    ERace Character::race() const
    {
        return impl_->race_;
    }

    void Character::race(ERace race)
    {
        if ((race < 0) || (race >= RaceCount))
            throw std::invalid_argument("Value is outside of allowed race bounds");

        impl_->race_ = race;
    }

    std::shared_ptr<Style> Character::style() const
    {
        return std::make_shared<Style>(impl_->style_);
    }

    void Character::style(const std::shared_ptr<Style>& style)
    {
        impl_->style_ = style->impl_;
    }
} // namespace Dominion
