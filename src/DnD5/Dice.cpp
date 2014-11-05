// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#include "Dice.h"

#include <boost/format.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>

#include <Core/log.h>

namespace DnD5
{
	class Dice::DiceImpl {
	public:
		DiceImpl() : rng(std::time(nullptr)) {}

		inline uint8_t Roll6() { return Roll(6); }
		inline uint8_t Roll20() { return Roll(20); }

	private:
		uint8_t Roll(uint8_t max) {
			boost::random::uniform_int_distribution<> dist(1, max);
			uint8_t res = dist(rng);

			LOGD << boost::format("Rolled a D%1%, got %2%") % (uint32_t)max % (uint32_t)res;

			return res;
		}

		boost::random::mt19937 rng;
	};

	//----------------------------------------------------------------------------------------------
	// DICE
	//----------------------------------------------------------------------------------------------
	Dice::Dice()
		: impl(new DiceImpl())
	{
	}

	inline uint8_t Dice::Roll6()
	{
		return impl->Roll6();
	}

	inline uint8_t Dice::Roll20()
	{
		return impl->Roll20();
	}
} // namespace DnD5