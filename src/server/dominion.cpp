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

#include "dominion.h"

#if defined(_WIN32)
#include <windows.h>
#endif

#include <dominion/api.h>
#include <dominion/dice.h>
#include <dominion/character/attributes.h>
#include <dominion/character/character.h>
#include <dominion/character/perk.h>
#include <dominion/character/style.h>

#include "utility/log.h"

namespace Tonkatsu
{
	void DominionLib::Initialise()
	{
#if defined(_WIN32)
		if (IsDebuggerPresent())
			Dominion::Initialise("../../data/dominion");
#else
		Dominion::Initialise("./data/dominion");
#endif

		db_ = Dominion::GetDatabase();

		auto npc = Dominion::CreateCharacter();
		auto dice = std::make_shared<Dominion::Dice>();
		auto styles = db_->GetStyles();
		auto attributes = Dominion::GetBaseAttributes();
		auto apr = Dominion::GetAttributeRoll(dice);

		for (auto style : styles)
			LOGD << style->name();

		npc->race(Dominion::RaceHuman);
		npc->style(styles[0]);
		npc->perk(dice->Roll());

		LOGD << npc->race();
		LOGD << npc->style()->name();

		auto perks = npc->perks();

		for (auto perk : perks)
			LOGD << perk->name();

		for (auto a : attributes)
			LOGD << (int)a;

		LOGD << "Attribute Points " << (int)std::get<0>(apr);
		LOGD << "Remainder " << (int)std::get<1>(apr);
	}
} // namespace Tonkatsu