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
#include <boost/shared_ptr.hpp>

#include <dominion/lore.h>
#include <dominion/race.h>

#include "testFramework.h"

struct LoreFixture : public BaseFixture<LoreFixture> {
	LoreFixture() :
		BaseFixture("DnD5_Lore.csv", { "GenerateFirstName", "GenerateLastName" })
	{
		for (int i = 0; i < (int)Dominion::ESubRaceDwarf::Count; ++i)
			races.emplace_back(std::make_shared<Dominion::Dwarf>(static_cast<Dominion::ESubRaceDwarf>(i)));

		for (int i = 0; i < (int)Dominion::ESubRaceElf::Count; ++i)
			races.emplace_back(std::make_shared<Dominion::Elf>(static_cast<Dominion::ESubRaceElf>(i)));

		for (int i = 0; i < (int)Dominion::ESubRaceHalfling::Count; ++i)
			races.emplace_back(std::make_shared<Dominion::Halfling>(static_cast<Dominion::ESubRaceHalfling>(i)));

		for (int i = 0; i < (int)Dominion::ESubRaceHuman::Count; ++i)
			races.emplace_back(std::make_shared<Dominion::Human>(static_cast<Dominion::ESubRaceHuman>(i)));
	}

	std::vector<std::shared_ptr<Dominion::IRace>> races;
};

BOOST_FIXTURE_TEST_SUITE(DnD5_Lore, LoreFixture);

BOOST_AUTO_TEST_CASE(FirstName)
{
	TestFunc([&] {
		for (const auto& iter : races) {
			BOOST_CHECK(Dominion::Lore::GenerateFirstName(iter, true).size() > 0);
			BOOST_CHECK(Dominion::Lore::GenerateFirstName(iter, false).size() > 0);
		}
	});
}

BOOST_AUTO_TEST_CASE(LastName)
{
	TestFunc([&] {
		for (const auto& iter : races) {
			BOOST_CHECK(Dominion::Lore::GenerateLastName(iter).size() > 0);
		}
	});
}


BOOST_AUTO_TEST_SUITE_END()