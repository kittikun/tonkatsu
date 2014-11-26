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

#include "attributes.h"

#include <iterator>
#include <algorithm>
#include <numeric>

#include "../dice.h"
#include "../impl/attribute_impl.h"
#include "../impl/dice_impl.h"

namespace Dominion
{
    Attributes::Attributes(AttributeArray a) :
        impl_(new AttributesImpl(a))
    {}

    Attributes::~Attributes()
    {}

    AttributeArray Attributes::GetBaseAttributes()
    {
        AttributeArray attributes;

        attributes.fill(1);

        return attributes;
    }

    AttributePointsRemainder Attributes::GetAttributeRoll(const std::shared_ptr<Dice>& dice)
    {
        std::array < uint8_t, 3 >  res;

        res.fill(dice->Roll());

        const uint8_t sum = std::accumulate(std::begin(res), std::end(res), uint8_t(0));

        return std::make_tuple(sum / 3, sum % 3);
    }
} // namespace Dominion
