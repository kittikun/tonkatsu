// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include <cstdint>
#include "definitions.h"

namespace DnD5
{
	struct Abilities
	{
		uint8_t Strenght;
		uint8_t Dexterity;
		uint8_t Constitution;
		uint8_t Intelligence;
		uint8_t Wisdom;
		uint8_t Charisma;
	};
}

#endif