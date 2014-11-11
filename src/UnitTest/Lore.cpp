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

#include <DnD5/Lore.h>

#include "TestFramework.h"

struct LoreFixture : public BaseFixture<LoreFixture> {
	LoreFixture() :
		BaseFixture("DnD5_Lore.csv", { "FirstName", "LastName" })
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(DnD5_Lore, LoreFixture);

BOOST_AUTO_TEST_CASE(FirstName)
{
	TestFunc([&] {
		BOOST_CHECK(DnD5::Lore::GenerateFirstName(DnD5::ERace::Dwarf, true).size() > 0);
		BOOST_CHECK(DnD5::Lore::GenerateFirstName(DnD5::ERace::Dwarf, false).size() > 0);
	});
}

BOOST_AUTO_TEST_CASE(LastName)
{
	TestFunc([&] {
		BOOST_CHECK(DnD5::Lore::GenerateLastName(DnD5::ERace::Dwarf).size() > 0);
	});
}


BOOST_AUTO_TEST_SUITE_END()