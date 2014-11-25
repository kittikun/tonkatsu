// Copyright(C) 2014 kittikun
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// This work is compatible with the Dominion Rules role-playing system.To learn more about
// Dominion Rules, visit the Dominion Rules web site at <http://www.dominionrules.org>

#include "perk_impl.h"

#include <boost/lexical_cast.hpp>

#include "classid.h"
#include "database_impl.h"

namespace Dominion
{
	int PerkImpl::LoadFromDB(void* data, int argc, char** argv, char** col)
	{
		DatabaseImpl* db = static_cast<DatabaseImpl*>(data);
		std::shared_ptr<PerkImpl> perk;

		for (int i = 0; i < argc; ++i) {
			if (strcmp(col[i], "Id") == 0) {
				uint32_t id = ClassID::Perk + boost::lexical_cast<uint32_t>(argv[i]);
				perk = std::make_shared<PerkImpl>(id);
			}

			if (strcmp(col[i], "type") == 0) {
				perk->type_ = boost::lexical_cast<EPerkType>(argv[i]);
			}
		}

		return 0;
	}

	bool PerkImpl::isRaceUsable(ERace race) const
	{
		return usableRace_[race];
	}
}