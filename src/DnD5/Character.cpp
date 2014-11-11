// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#include "Character.h"

#include "Abilities.h"
#include "Race.h"

namespace DnD5
{
	class CharacterImpl
	{
	public:
		CharacterImpl(const std::shared_ptr<Abilities>& ab, Profession p, const std::shared_ptr<IRace>& r) :
			abilities(ab),
			profession(p),
			race(r)
		{
		}

	private:
		std::shared_ptr<Abilities> abilities;
		Profession profession;
		std::shared_ptr<IRace> race;
	};

	//----------------------------------------------------------------------------------------------
	// CHARACTER
	//----------------------------------------------------------------------------------------------
	Character::Character(const std::shared_ptr<Abilities>& ab, Profession p, const std::shared_ptr<IRace>& r)
		: impl(new CharacterImpl(ab, p, r))
	{
	}

	Character::~Character()
	{
	}
} // namespace DnD5