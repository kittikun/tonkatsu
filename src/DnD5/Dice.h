// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#ifndef DICE_H
#define DICE_H

#include <array>
#include <cstdint>
#include <memory>

#include <core/platform.h>

namespace DnD5
{
	class KATSU_API Dice
	{
	public:
		Dice();
		~Dice();

		const uint8_t Roll6() const;
		const uint8_t Roll20() const;

	private:
		class DiceImpl;
		std::unique_ptr<DiceImpl> impl;
	};
} // namespace DnD5

#endif // DICE_H
