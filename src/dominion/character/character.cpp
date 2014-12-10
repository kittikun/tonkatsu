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

#include <numeric>
#include <boost/format.hpp>

#include "attributes.h"
#include "perk.h"
#include "style.h"
#include "../impl/attribute_impl.h"
#include "../impl/character_impl.h"
#include "../impl/perk_impl.h"
#include "../impl/style_impl.h"

namespace Dominion
{
    Character::Character(const std::shared_ptr<CharacterImpl>& impl) :
        impl_(impl)
    {}

    Character::~Character()
    {}

    std::shared_ptr<Attributes> Character::attributes() const
    {
        return std::make_shared<Attributes>(impl_->attributes_);
    }

    std::vector<std::shared_ptr<Perk>> Character::perks() const
    {
        std::vector<std::shared_ptr<Perk>> res;

        res.reserve(impl_->perks_.size());

        for (size_t i = 0; i < impl_->perks_.size(); ++i)
            res.push_back(std::make_shared<Perk>(impl_->perks_[i]));

        return res;
    }

    const ERace Character::race() const
    {
        return impl_->race_;
    }

    std::shared_ptr<Style> Character::style() const
    {
        return std::make_shared<Style>(impl_->style_);
    }
} // namespace Dominion
