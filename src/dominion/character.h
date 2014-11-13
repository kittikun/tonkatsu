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

#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>

#include "attributes.h"
#include "definitions.h"

namespace Dominion
{
	class Abilities;
	class IRace;

	class Character
	{
		Character(const AttributeArray&, Style, const std::shared_ptr<IRace>&);
		~Character();

	private:
		class CharacterImpl;

		std::unique_ptr<CharacterImpl> impl;
	};
}

#endif