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

#ifndef ABILITIES_H
#define ABILITIES_H

#include <array>
#include <memory>
#include <tuple>

#include "../platform.h"

namespace Dominion
{
	enum EAttribute
	{
		// (DR3.1.1 p9, 1-1 THE SIX ATTRIBUTES)
		Agility,
		Intuition,
		Intellect,
		Luck,
		Stamina,
		Vigour,
		Count
	};

	typedef std::array<uint8_t, EAttribute::Count> AttributeArray;

	// Number of points / Remainder
	typedef std::tuple<uint8_t, uint8_t> AttributePointsRemainder;

	class Dice;

	class KATSU_API Attributes
	{
	public:
		Attributes(AttributeArray);
		~Attributes();

		Attributes(const Attributes&) = delete;
		Attributes& operator=(const Attributes&) = delete;

		// (DR3.1.1 p30, 4-6 STEP THREE: DETERMINE ATTRIBUTE STATS)
		// 1. Assign a minimum score of 1 to each of your character’s six Attributes.
		static AttributeArray GetBaseAttributes();

		// (DR3.1.1 p30, 4-6 STEP THREE: DETERMINE ATTRIBUTE STATS)
		// 2. Roll the twelve - sided die three times and record your results.
		// 3. Calculate the average of your three rolls. This is done by adding the three rolls together and
		// dividing the sum by three.The result is the number of Attribute Points you have to distribute between
		// your six Attributes.Make note of the remainder, if you get one
		static AttributePointsRemainder GetAttributeRoll(const std::shared_ptr<Dice>& dice);

	private:
		class AttributesImpl;

		std::unique_ptr<AttributesImpl> impl_;
	};
}

#endif