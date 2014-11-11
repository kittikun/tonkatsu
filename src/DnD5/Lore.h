// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#ifndef LORE_H
#define LORE_H

#include <memory>
#include <string>

#include <Core/Platform.h>

namespace DnD5
{
	class IRace;

	namespace Lore 
	{
		std::string KATSU_API GenerateFirstName(const std::shared_ptr<IRace>& race, bool isMale);
		std::string KATSU_API GenerateLastName(const std::shared_ptr<IRace>& race);
	} // namespace Lore
} // namespace DnD5

#endif // LORE_H