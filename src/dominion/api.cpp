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
//
// This work is compatible with the Dominion Rules role-playing system.To learn more about
// Dominion Rules, visit the Dominion Rules web site at <http://www.dominionrules.org>

#include "api.h"

#include <boost/filesystem.hpp>

namespace Dominion
{
	void Initialise(const std::string& dataPath)
	{
		boost::filesystem::path path(dataPath);
		boost::filesystem::path file("test.txt");
		boost::filesystem::path canonical = boost::filesystem::canonical(dataPath / file);

		if (boost::filesystem::exists(canonical)) {
			int i = 0;
		}
	}
} // namespace Dominion