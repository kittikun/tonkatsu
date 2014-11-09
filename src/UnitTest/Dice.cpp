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
#include <numeric>
#include <memory>
#include <iterator>

#include <DnD5/Dice.h>

#include "minicsv.h"

struct DiceFixture {
	DiceFixture() :
		dice(new DnD5::Dice()),
		os("DnD5_Dice.csv", std::ios_base::app)
	{
		os.set_delimiter(',');
	}

	~DiceFixture() {}

	std::unique_ptr<DnD5::Dice> dice;
	csv::ofstream os;
};

BOOST_FIXTURE_TEST_SUITE(DnD5_Dice, DiceFixture)

BOOST_AUTO_TEST_CASE(Roll6)
{
	std::array<std::chrono::milliseconds::rep, 10> time;

	for (int i = 0; i < 10; ++i) {
		auto t1 = std::chrono::high_resolution_clock::now();

		for (int j = 0; j < 1000; ++j) {
			uint8_t rnd = dice->Roll6();
			BOOST_CHECK((rnd > 0) && (rnd <= 6));
		}
		auto t2 = std::chrono::high_resolution_clock::now();

		time[i] = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	}

	size_t avg = std::accumulate(begin(time), end(time), (std::chrono::milliseconds::rep)0) / time.size();

	if (os.is_open())
	{
		os << "Roll6" << avg << NEWLINE;
	}
}

BOOST_AUTO_TEST_CASE(Roll20)
{
	std::array<std::chrono::milliseconds::rep, 10> time;

	for (int i = 0; i < 10; ++i) {
		auto t1 = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < 1000; ++i) {
			uint8_t rnd = dice->Roll20();
			BOOST_CHECK((rnd > 0) && (rnd <= 20));
		}
		auto t2 = std::chrono::high_resolution_clock::now();

		time[i] = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	}

	size_t avg = std::accumulate(begin(time), end(time), (std::chrono::milliseconds::rep)0) / time.size();

	if (os.is_open())
	{
		os << "Roll20" << avg << NEWLINE;
	}
}

BOOST_AUTO_TEST_CASE(AbilityRoll)
{
	std::array<std::chrono::milliseconds::rep, 10> time;

	for (int i = 0; i < 10; ++i) {
		auto t1 = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < 1000; ++i) {
			auto aRoll = dice->AbilityRoll();
			auto acc = std::accumulate(begin(aRoll), end(aRoll), 0);

			BOOST_CHECK(acc > 0);
			BOOST_CHECK(acc <= (18 * 6));
		}
		auto t2 = std::chrono::high_resolution_clock::now();

		time[i] = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	}
	size_t avg = std::accumulate(begin(time), end(time), (std::chrono::milliseconds::rep)0) / time.size();

	if (os.is_open())
	{
		os << "AbilityRoll" << avg << NEWLINE;
	}
}

BOOST_AUTO_TEST_SUITE_END()
