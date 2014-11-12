// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#include "dice.h"

#include <algorithm>
#include <ctime>
#include <iterator>
#include <numeric>
#include <random>

namespace DnD5
{
	class Dice::DiceImpl {
	public:
		DiceImpl() : rng((uint32_t)std::time(nullptr))
		{
		}

		inline const uint8_t Roll6() { return Roll(6); }
		inline const uint8_t Roll20() { return Roll(20); }

	private:
		const uint8_t Roll(uint8_t max) {
			std::uniform_int_distribution<> dist(1, max);
			uint8_t res = (uint8_t)dist(rng);

			return res;
		}

	private:
		std::mt19937 rng;
	};

	//----------------------------------------------------------------------------------------------
	// DICE
	//----------------------------------------------------------------------------------------------
	Dice::Dice()
		: impl(new DiceImpl())
	{
	}

	Dice::~Dice()
	{
	}

	const uint8_t Dice::Roll6() const
	{
		return impl->Roll6();
	}

	const uint8_t Dice::Roll20() const
	{
		return impl->Roll20();
	}
} // namespace DnD5