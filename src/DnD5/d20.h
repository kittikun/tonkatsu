// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#ifndef D20_H
#define D20_H

#include <cstdint>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include <Core/platform.h>

namespace DnD5
{
	class D20
	{
	public:
		KATSU_API uint8_t Roll();

	private:
		boost::random::mt19937 rng;
	};
} // namespace DnD5

#endif // D20_H