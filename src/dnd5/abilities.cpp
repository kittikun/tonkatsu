// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#include "abilities.h"

#include <algorithm>
#include <numeric>

#include "dice.h"

namespace DnD5
{
	class Abilities::AbilitiesImpl
	{
	public:
		AbilitiesImpl(const std::array<uint8_t, 6>& a) :
			abilities(a)
		{
		}

		AbilitiesImpl(const AbilitiesImpl& other) : abilities(other.abilities) {}

		AbilitiesImpl & operator=(const AbilitiesImpl& other)
		{
			AbilitiesImpl tmp(other);
			*this = std::move(tmp);
			return *this;
		}

		uint8_t Strenght() const { return abilities[EAbility::Strenght]; }
		uint8_t Dexterity() const { return abilities[EAbility::Dexterity]; }
		uint8_t Constitution() const { return abilities[EAbility::Constitution]; }
		uint8_t Intelligence() const { return abilities[EAbility::Intelligence]; }
		uint8_t Wisdom() const { return abilities[EAbility::Wisdom]; }
		uint8_t Charisma() const { return abilities[EAbility::Charisma]; }

	private:
		const std::array<uint8_t, 6>& abilities;
	};

	//----------------------------------------------------------------------------------------------
	// ABILITIES
	//----------------------------------------------------------------------------------------------
	Abilities::Abilities(const std::array<uint8_t, 6>& a) :
		impl(new AbilitiesImpl(a))
	{
	}

	Abilities::~Abilities()
	{
	}

	// (PlayerDnDBasicRules_v0.2 p7 - Determine Ability Scores)
	// Roll four 6 - sided dice and record the total of
	// the highest three dice on a piece of scratch paper.
	uint8_t AbilityFromRoll(const std::shared_ptr<Dice>& dice)
	{
		std::array<uint8_t, 4> pool;

		for (int i = 0; i < 4; ++i)
			pool[i] = dice.get()->Roll6();

		std::sort(std::begin(pool), std::end(pool));

		return std::accumulate(std::begin(pool) + 1, std::end(pool), (uint8_t)0);
	}

	std::array<uint8_t, 6> Abilities::AbilitiesFromRoll(const std::shared_ptr<Dice>& dice)
	{
		std::array<uint8_t, 6> res;

		std::for_each(std::begin(res), std::end(res), [&](uint8_t& n) { n = AbilityFromRoll(dice); });

		return res;
	}

	std::array<uint8_t, 6> Abilities::AbilitiesFromStandard()
	{
		return std::array < uint8_t, 6 > { 15, 14, 13, 12, 10, 8 };
	}
} // namespace DnD5
