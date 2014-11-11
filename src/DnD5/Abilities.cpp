// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#include "Abilities.h"

namespace DnD5
{
	class AbilitiesImpl
	{
	public:
		AbilitiesImpl(const std::array<uint8_t, 6>& abilities) :
			strenght(abilities[0]),
			dexterity(abilities[1]),
			constitution(abilities[2]),
			intelligence(abilities[3]),
			wisdom(abilities[4]),
			charisma(abilities[5])
		{
		}

		uint8_t Strenght() const { return strenght; }
		uint8_t Dexterity() const { return dexterity; }
		uint8_t Constitution() const { return constitution; }
		uint8_t Intelligence() const { return intelligence; }
		uint8_t Wisdom() const { return wisdom; }
		uint8_t Charisma() const { return charisma; }

	private:
		uint8_t strenght;
		uint8_t dexterity;
		uint8_t constitution;
		uint8_t intelligence;
		uint8_t wisdom;
		uint8_t charisma;
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
} // namespace DnD5