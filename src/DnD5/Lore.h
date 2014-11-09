// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#ifndef LORE_H
#define LORE_H

#include <string>

#include <Core/Platform.h>

#include "Race.h"

namespace DnD5
{
	namespace Lore 
	{
		std::string KATSU_API GenerateFirstName(ERace race, bool isMale);
		std::string KATSU_API GenerateLastName(ERace race);
	} // namespace Lore
} // namespace DnD5

#endif // LORE_H