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

#ifndef DEFINITION_H
#define DEFINITION_H

#include <cstdint>

namespace Dominion
{
	// (DR3.1.1 p26, 4-2 CHARACTER STYLES)
	enum class Style : uint8_t {
		Crusader,
		Fool,
		MerchantAdventurer,
		Monk,
		Priest,
		Ranger,
		Rogue,
		Soldier,
		Witch
	};
} // namespace Dominion

#endif // DEFINITION_H