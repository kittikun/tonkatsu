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

#include <boost/scoped_ptr.hpp>
#include <iostream>

#include <Core/log.h>
#include <Bible/d20.h>

int main(int argc, char* argv[])
{
	Tonkatsu::Core::Log::Initialize();

	LOGC << "Hello World!";

	boost::scoped_ptr<Bible::D20> dice(new Bible::D20());

	dice->Roll();

	std::cin.get();

	return 0;
}