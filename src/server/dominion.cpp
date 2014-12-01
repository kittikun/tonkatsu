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

#include <chrono>

#if defined(_WIN32)
#include <windows.h>
#endif

#include <dominion/api.h>
#include <dominion/character/style.h>

#include "utility/log.h"

namespace Tonkatsu
{
	void DominionLib::Initialise()
	{
		auto t1 = std::chrono::system_clock::now();

#if defined(_WIN32)
		if (IsDebuggerPresent())
			Dominion::Initialise("../../data/dominion");
#else
		Dominion::Initialise("./data/dominion");
#endif

		auto t2 = std::chrono::system_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();

		LOGD << "Initialization time " << elapsed << "ms";

		t1 = std::chrono::system_clock::now();
		db_ = Dominion::GetDatabase();
		t2 = std::chrono::system_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();

		auto styles = db_->GetStyles();

		for (auto s : styles)
			LOGD << s->name();

		LOGD << "GetStyles time " << elapsed << "ms";
	}
} // namespace Tonkatsu