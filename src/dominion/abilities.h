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

#include <core/platform.h>

namespace Dominion
{
	enum EAbility
	{
		Strenght,
		Dexterity,
		Constitution,
		Intelligence,
		Wisdom,
		Charisma
	};

	class Dice;

	class KATSU_API Abilities
	{
	public:
		Abilities(const std::array<uint8_t, 6>&);
		~Abilities();

		// (PlayerDnDBasicRules_v0.2 p7 - Determine Ability Scores)
		// Roll four 6-sided dice and record the total of the highest three dice on a piece
		// of scratch paper. Do this five more times, so that you have six numbers.
		static std::array<uint8_t, 6> AbilitiesFromRoll(const std::shared_ptr<Dice>& dice);

		// (PlayerDnDBasicRules_v0.2 p7 - Determine Ability Scores)
		// If you want to save time or don’t like the idea of randomly
		// determining ability scores, you can use the following
		// scores instead : 15, 14, 13, 12, 10, 8.
		static std::array<uint8_t, 6> AbilitiesFromStandard();

		// (PlayerDnDBasicRules_v0.2 p8 - Variant: Customizing Ability Scores)
		// You have 27 points to spend on your ability scores. The cost of each score is shown on
		// the Ability Score Point Cost table. Using this method, 15 is the highest ability score
		// you can end up with, before applying racial increases.You can’t have a score lower than 8
		//	Score	Cost
		//	8		0
		//	9		1
		//	10		2
		//	11		3
		//	12		4
		//	13		5
		//	14		7
		//	15		9
		static std::array < uint8_t, 6 > AbitilitesFromPoints(const std::array<uint8_t, 6>& points);

	private:
		class AbilitiesImpl;

		std::unique_ptr<AbilitiesImpl> impl;
	};
}

#endif