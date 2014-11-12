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

#include <dnd5/abilities.h>
#include <dnd5/dice.h>

#include "testFramework.h"

struct AbilityFixture : public BaseFixture < AbilityFixture > {
	AbilityFixture() :
		BaseFixture("DnD5_Ability.csv", { "AbilitiesFromRoll" })
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(DnD5_Ability, AbilityFixture)

BOOST_AUTO_TEST_CASE(AbilitiesFromRoll)
{
	std::shared_ptr<DnD5::Dice> dice = std::make_shared<DnD5::Dice>();

	TestFunc([&] {
		auto aRoll = DnD5::Abilities::AbilitiesFromRoll(dice);
		auto acc = std::accumulate(begin(aRoll), end(aRoll), 0);

		BOOST_CHECK(acc > 0);
		BOOST_CHECK(acc <= (18 * 6));
	});
}

BOOST_AUTO_TEST_SUITE_END()