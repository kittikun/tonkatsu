// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#include "Dice.h"

#include <algorithm>
#include <ctime>
#include <numeric>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>

namespace DnD5
{
  class DiceImpl {
	public:
    DiceImpl() : rng((uint32_t)std::time(nullptr)) {}

		inline uint8_t Roll6() { return Roll(6); }
		inline uint8_t Roll20() { return Roll(20); }

		std::array<uint8_t, 6> CharacterRoll()
		{
			std::array<uint8_t, 6> res;

			std::for_each(begin(res), end(res), [this](uint8_t& n) { n = AbilityRoll(); });

			return res;
		}

	private:
		uint8_t Roll(uint8_t max) {
			boost::random::uniform_int_distribution<> dist(1, max);
			uint8_t res = dist(rng);

			return res;
		}

		// PlayerDnDBasicRules_v0.2 p7 (Determine Ability Scores)
		//
		// Roll four 6 - sided dice and record the total of
		// the highest three dice on a piece of scratch paper.
		uint8_t AbilityRoll()
		{
			std::array<uint8_t, 4> pool;

			for (int i = 0; i < 4; ++i)
				pool[i] = Roll6();

			std::sort(begin(pool), end(pool));

			return std::accumulate(begin(pool) + 1, end(pool), 0);
		}

	private:
		boost::random::mt19937 rng;
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

	uint8_t Dice::Roll6() const
	{
		return impl->Roll6();
	}

	uint8_t Dice::Roll20() const
	{
		return impl->Roll20();
	}

	const std::array<uint8_t, 6> Dice::CharacterRoll() const
	{
		return impl->CharacterRoll();
	}
} // namespace DnD5
