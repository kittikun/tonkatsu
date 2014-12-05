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

#include "api.h"

#include <numeric>

#include "database.h"
#include "dice.h"
#include "impl/api_impl.h"
#include "impl/dice_impl.h"

namespace Dominion
{
    std::shared_ptr<Character> CreateCharacter()
    {
        return ApiImpl::instance().CreateCharacter();
    }

    void Initialise(const std::string& dataPath)
    {
        ApiImpl::instance().LoadDatabase(dataPath);
    }

    std::shared_ptr<DataBase> GetDatabase()
    {
        return ApiImpl::instance().database();
    }

    AttributeArray GetBaseAttributes()
    {
        AttributeArray attributes;

        attributes.fill(1);

        return attributes;
    }

    AttributePointsRemainder GetAttributeRoll(const std::shared_ptr<Dice>& dice)
    {
        std::array < uint8_t, 3 >  res;

        for (int i = 0; i < res.size(); ++i)
            res[i] = dice->Roll();

        const uint8_t sum = std::accumulate(std::begin(res), std::end(res), uint8_t(0));

        return std::make_tuple(sum / 3, sum % 3);
    }
} // namespace Dominion
