// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#ifndef DICE_H
#define DICE_H

#include <array>
#include <cstdint>
#include <memory>

#include <Core/Platform.h>

namespace DnD5
{
    class DiceImpl;

    class KATSU_API Dice
    {
    public:
        Dice();
        ~Dice();

        uint8_t Roll6() const;
        uint8_t Roll20() const;

        const std::array<uint8_t, 6> AbilityRoll() const;

    private:
        std::unique_ptr<DiceImpl> impl;
    };
} // namespace DnD5

#endif // DICE_H
