// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#include "d20.h"

#include <boost/format.hpp>

#include <Core/log.h>

namespace DnD5
{
	uint8_t D20::Roll()
	{
		boost::random::uniform_int_distribution<> dist(1, 20);

		uint8_t res = dist(rng);

		LOGC << boost::format("Rolled a %1%") % (int)res;

		return dist(rng);
	}
} // namespace DnD5