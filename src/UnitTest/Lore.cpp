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

#include <DnD5/Lore.h>
#include <DnD5/Race.h>

#include "TestFramework.h"

struct LoreFixture : public BaseFixture<LoreFixture> {
	LoreFixture() :
		BaseFixture("DnD5_Lore.csv", { "GenerateFirstName", "GenerateLastName" })
	{
		for (int i = 0; i < (int)DnD5::ESubRaceDwarf::Count; ++i)
			races.emplace_back(std::make_shared<DnD5::Dwarf>(static_cast<DnD5::ESubRaceDwarf>(i)));

		for (int i = 0; i < (int)DnD5::ESubRaceElf::Count; ++i)
			races.emplace_back(std::make_shared<DnD5::Elf>(static_cast<DnD5::ESubRaceElf>(i)));

		for (int i = 0; i < (int)DnD5::ESubRaceHalfling::Count; ++i)
			races.emplace_back(std::make_shared<DnD5::Halfling>(static_cast<DnD5::ESubRaceHalfling>(i)));

		for (int i = 0; i < (int)DnD5::ESubRaceHuman::Count; ++i)
			races.emplace_back(std::make_shared<DnD5::Human>(static_cast<DnD5::ESubRaceHuman>(i)));
	}

	std::vector<std::shared_ptr<DnD5::IRace>> races;
};

BOOST_FIXTURE_TEST_SUITE(DnD5_Lore, LoreFixture);

BOOST_AUTO_TEST_CASE(FirstName)
{
	TestFunc([&] {
		for (const auto& iter : races) {
			BOOST_CHECK(DnD5::Lore::GenerateFirstName(iter, true).size() > 0);
			BOOST_CHECK(DnD5::Lore::GenerateFirstName(iter, false).size() > 0);
		}
	});
}

BOOST_AUTO_TEST_CASE(LastName)
{
	TestFunc([&] {
		for (const auto& iter : races) {
			BOOST_CHECK(DnD5::Lore::GenerateLastName(iter).size() > 0);
		}
	});
}


BOOST_AUTO_TEST_SUITE_END()