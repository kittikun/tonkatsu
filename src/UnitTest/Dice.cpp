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

#include <numeric>
#include <boost\scoped_ptr.hpp>

#include <DnD5\Dice.h>

BOOST_AUTO_TEST_SUITE(DnD5_Dice)

BOOST_AUTO_TEST_CASE(Roll6)
{
    boost::scoped_ptr<DnD5::Dice> dice(new DnD5::Dice());

    BOOST_CHECK(dice->Roll6() > 0);
    BOOST_CHECK(dice->Roll6() <= 6);
    BOOST_CHECK(dice->Roll20() > 0);
    BOOST_CHECK(dice->Roll20() <= 20);
}

BOOST_AUTO_TEST_CASE(Roll20)
{
    boost::scoped_ptr<DnD5::Dice> dice(new DnD5::Dice());

    BOOST_CHECK(dice->Roll20() > 0);
    BOOST_CHECK(dice->Roll20() <= 20);
}

BOOST_AUTO_TEST_CASE(CharacterRoll)
{
    boost::scoped_ptr<DnD5::Dice> dice(new DnD5::Dice());

    auto cRoll = dice->CharacterRoll();
    auto acc = std::accumulate(begin(cRoll), end(cRoll), 0);

    BOOST_CHECK(acc > 0);
    BOOST_CHECK(acc <= (18 * 6));
}

BOOST_AUTO_TEST_SUITE_END()