// Copyright(C) 2014 kittikun
//
// This program is free software : you can redistribute it and / or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.If not, see <http://www.gnu.org/licenses/>.
//
// This work is compatible with the Dominion Rules role-playing system.To learn more about
// Dominion Rules, visit the Dominion Rules web site at <http://www.dominionrules.org>

#ifndef ABILITIES_H
#define ABILITIES_H

#include <array>
#include <memory>
#include <tuple>

#include <core/platform.h>

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