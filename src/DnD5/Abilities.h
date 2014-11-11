// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#ifndef ABILITIES_H
#define ABILITIES_H

#include <array>
#include <memory>

namespace DnD5
{
	class AbilitiesImpl;

	class Abilities
	{
		Abilities(const std::array<uint8_t, 6>&);
		~Abilities();

	private:
		std::unique_ptr<AbilitiesImpl> impl;
	};
}

#endif