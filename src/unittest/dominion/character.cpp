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

#include <chrono>
#include <random>
#include <vector>
#include <dominion/api.h>
#include <dominion/database.h>
#include <dominion/dice.h>
#include <dominion/character/character.h>
#include <dominion/character/style.h>

#include "../testFramework.h"

struct CharacterFixture : public BaseFixture < CharacterFixture, std::chrono::milliseconds > {
	CharacterFixture() :
		BaseFixture{ "Dominion_Characters.csv", { "Style", "Perk" } }
	{
		std::random_device rd;

		rng_ = std::mt19937{ rd() };
		db_ = Dominion::GetDatabase();
	}

	std::mt19937 rng_;
	std::shared_ptr<Dominion::DataBase> db_;
};

BOOST_FIXTURE_TEST_SUITE(Dominion_Character, CharacterFixture)

BOOST_AUTO_TEST_CASE(Style)
{
	std::random_device rd;
	std::mt19937 rng_{ rd() };
	std::shared_ptr<Dominion::Character> character = Dominion::CreateCharacter();
	std::vector<std::shared_ptr<Dominion::Style>> styles = db_->GetStyles();

	TestFunc(1000, [&] {
		size_t index = std::uniform_int_distribution < size_t > { 0, styles.size() - 1 }(rng_);
		std::shared_ptr<Dominion::Style> target = styles[index];

		character->style(target);

		BOOST_CHECK(character->style()->name() == target->name());
	});
}

BOOST_AUTO_TEST_CASE(Race)
{
	std::shared_ptr<Dominion::Character> character = Dominion::CreateCharacter();

	for (int i = 0; i < Dominion::RaceCount; ++i)
		BOOST_CHECK_NO_THROW(character->race((Dominion::ERace)i));

	BOOST_CHECK_THROW(character->race((Dominion::ERace) - 1), std::invalid_argument);
	BOOST_CHECK_THROW(character->race(Dominion::RaceCount), std::invalid_argument);
	BOOST_CHECK_THROW(character->race((Dominion::ERace)(Dominion::RaceCount + 1)), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Perk)
{
	std::shared_ptr<Dominion::Character> character = Dominion::CreateCharacter();
	std::shared_ptr<Dominion::Dice> dice = std::make_shared<Dominion::Dice>();

	BOOST_CHECK_THROW(character->perk(0), std::invalid_argument);
	BOOST_CHECK_THROW(character->perk(20), std::invalid_argument);

	// race is not set and error should be thrown
	BOOST_CHECK_THROW(character->perk(20), std::logic_error);

	TestFunc(1000, [&] {
		for (int i = 0; i < Dominion::RaceCount; ++i)
		{
			character->race((Dominion::ERace)i);

			character->perk(dice->Roll());
		}

		BOOST_CHECK(static_cast<bool>(character->perk()));
	});
}

BOOST_AUTO_TEST_SUITE_END()