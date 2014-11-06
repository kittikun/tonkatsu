// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//
#ifndef DEFINITION_H
#define DEFINITION_H

#include <cstdint>

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

	enum class Class : uint8_t {
		Cleric,
		Fighther,
		Rogue,
		Wizard
	};
} // namespace DnD5

#endif // DEFINITION_H