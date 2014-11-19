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

#include <dominion/character/perk.h>

#include "../testFramework.h"

#include <iostream>
#include <fstream>
#include <cereal/archives/json.hpp>

struct PerkFixture : public BaseFixture < PerkFixture > {
	PerkFixture() :
		BaseFixture("Dominion_Perk.csv", { "PerkSerialize, PerkDeserialize" })
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(Dominion_Perk, PerkFixture)

BOOST_AUTO_TEST_CASE(PerkSerialize)
{
	TestFunc([&] {
		Dominion::Perk perk1;
		Dominion::Perk perk2;
		Dominion::Perk perk3;

		perk1.set_type(Dominion::EPerkType::Attribute);
		perk2.set_type(Dominion::EPerkType::Passive);
		perk3.set_type(Dominion::EPerkType::Skill);

		std::ofstream ofs("perk.txt");
		cereal::JSONOutputArchive oarchive(ofs);

		oarchive(CEREAL_NVP(perk1), CEREAL_NVP(perk2), CEREAL_NVP(perk3));
	});
}

BOOST_AUTO_TEST_CASE(PerkDeserialize)
{
	TestFunc([&] {
		Dominion::Perk perk1;
		Dominion::Perk perk2;
		Dominion::Perk perk3;

		std::ifstream ifs("perk.txt");
		cereal::JSONInputArchive iarchive(ifs);

		iarchive(CEREAL_NVP(perk1), CEREAL_NVP(perk2), CEREAL_NVP(perk3));

		BOOST_CHECK(perk1.type() == Dominion::EPerkType::Attribute);
		BOOST_CHECK(perk2.type() == Dominion::EPerkType::Passive);
		BOOST_CHECK(perk2.type() == Dominion::EPerkType::Skill);
	});
}

BOOST_AUTO_TEST_SUITE_END()