// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#ifndef DICE_H
#define DICE_H

#include <cstdint>

#include <Core/platform.h>

namespace DnD5
{
	class KATSU_API Dice
	{
	public:
		Dice();

		uint8_t Roll6();
		uint8_t Roll20();

	private:
		class DiceImpl;
		DiceImpl* impl;
	};
} // namespace DnD5

#endif // DICE_H