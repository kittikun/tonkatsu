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

#include <boost/test/unit_test.hpp>
#include <memory>

#include <DnD5/Dice.h>

#include "TestFramework.h"


struct DiceFixture : public BaseFixture<DiceFixture> {
	DiceFixture() :
		BaseFixture("DnD5_Dice.csv", { "Roll6", "Roll20", "AbilityRoll" }),
		dice(new DnD5::Dice())
	{
	}

	std::unique_ptr<DnD5::Dice> dice;
};

BOOST_FIXTURE_TEST_SUITE(DnD5_Dice, DiceFixture)

BOOST_AUTO_TEST_CASE(Roll6)
{
	TestFunc([&] {
		uint8_t rnd = dice->Roll6();
		BOOST_CHECK((rnd > 0) && (rnd <= 6));
	});
}

BOOST_AUTO_TEST_CASE(Roll20)
{
	TestFunc([&] {
		uint8_t rnd = dice->Roll20();
		BOOST_CHECK((rnd > 0) && (rnd <= 20));
	});
}

BOOST_AUTO_TEST_CASE(AbilityRoll)
{
	TestFunc([&] {
		auto aRoll = dice->AbilityRoll();
		auto acc = std::accumulate(begin(aRoll), end(aRoll), 0);

		BOOST_CHECK(acc > 0);
		BOOST_CHECK(acc <= (18 * 6));
	});
}

BOOST_AUTO_TEST_SUITE_END()
