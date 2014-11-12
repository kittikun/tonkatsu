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

#include "dice.h"

#include <algorithm>
#include <ctime>
#include <iterator>
#include <numeric>
#include <random>

namespace Dominion
{
	class Dice::DiceImpl {
	public:
		DiceImpl() : rng((uint32_t)std::time(nullptr))
		{
		}

		inline const uint8_t Roll6() { return Roll(6); }
		inline const uint8_t Roll20() { return Roll(20); }

	private:
		const uint8_t Roll(uint8_t max) {
			std::uniform_int_distribution<> dist(1, max);
			uint8_t res = (uint8_t)dist(rng);

			return res;
		}

	private:
		std::mt19937 rng;
	};

	//----------------------------------------------------------------------------------------------
	// DICE
	//----------------------------------------------------------------------------------------------
	Dice::Dice()
		: impl(new DiceImpl())
	{
	}

	Dice::~Dice()
	{
	}

	const uint8_t Dice::Roll6() const
	{
		return impl->Roll6();
	}

	const uint8_t Dice::Roll20() const
	{
		return impl->Roll20();
	}
} // namespace Dominion