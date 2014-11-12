// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>

#include "definitions.h"

namespace DnD5
{
	class Abilities;
	class IRace;

	class Character
	{
		Character(const std::shared_ptr<Abilities>&, Profession, const std::shared_ptr<IRace>&);
		~Character();

	private:
		class CharacterImpl;

		std::unique_ptr<CharacterImpl> impl;
	};
}

#endif