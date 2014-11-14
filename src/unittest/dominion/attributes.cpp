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

#include <dominion/character/attributes.h>
#include <dominion/dice.h>

#include "../testFramework.h"

struct AttributeFixture : public BaseFixture < AttributeFixture > {
	AttributeFixture() :
		BaseFixture("Dominion_Attributes.csv", { "GetBaseAttributes", "GetAttributeRoll" })
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(Dominion_Ability, AttributeFixture)

BOOST_AUTO_TEST_CASE(GetBaseAttributes)
{
	TestFunc([&] {
		auto attribs = Dominion::Attributes::GetBaseAttributes();

		BOOST_CHECK(std::accumulate(std::begin(attribs), std::end(attribs), 0) == Dominion::EAttribute::Count);
	});
}

BOOST_AUTO_TEST_CASE(GetAttributeRoll)
{
	std::shared_ptr<Dominion::Dice> dice = std::make_shared<Dominion::Dice>();

	TestFunc([&] {
		auto aRoll = Dominion::Attributes::GetAttributeRoll(dice);

		BOOST_CHECK(std::get<0>(aRoll) > 0);
		BOOST_CHECK(std::get<1>(aRoll) >= 0);
	});
}

BOOST_AUTO_TEST_SUITE_END()