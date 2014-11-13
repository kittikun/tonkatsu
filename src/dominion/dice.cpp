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
		DiceImpl()
		{
			std::random_device rd;
			rng = std::mt19937{ rd() };
		}

		const uint16_t Roll(uint16_t max)
		{
			return std::uniform_int_distribution < uint16_t > { 1, max }(rng);
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

	const uint16_t Dice::Roll() const
	{
		return impl->Roll(12);
	}
} // namespace Dominion