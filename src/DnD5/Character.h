// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include <cstdint>
#include <memory>

#include "Definitions.h"
#include "Race.h"

namespace DnD5
{
	class Character
	{
		explicit Character(Abilities, Class, std::shared_ptr<IRace> race);

	private:
		Abilities abilities;
		Class profession;
		std::shared_ptr<IRace> race;
	};
}

#endif