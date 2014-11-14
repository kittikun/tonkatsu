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

#include "character.h"

#include "attributes.h"
#include "definitions.h"
#include "race.h"

namespace Dominion
{
	class Character::CharacterImpl
	{
	public:
		CharacterImpl(const AttributeArray& ab, Style p, const std::shared_ptr<IRace>& r) :
			abilities(ab),
			Style(p),
			race(r)
		{
		}

	private:
		AttributeArray abilities;
		Style Style;
		std::shared_ptr<IRace> race;
	};

	//----------------------------------------------------------------------------------------------
	// CHARACTER
	//----------------------------------------------------------------------------------------------
	Character::Character(const AttributeArray& ab, Style p, const std::shared_ptr<IRace>& r)
		: impl{ new CharacterImpl(ab, p, r) }
	{
	}

	Character::~Character()
	{
	}
} // namespace Dominion