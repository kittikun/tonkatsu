// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#ifndef DICE_H
#define DICE_H

#include <cstdint>
#include <memory>

#include <Core/Platform.h>

namespace DnD5
{
    class DiceImpl;
    template class KATSU_API std::unique_ptr<DiceImpl>;

    class KATSU_API Dice
    {
    public:
        Dice();
        ~Dice();

        uint8_t Roll6();
        uint8_t Roll20();

    private:

        std::unique_ptr<DiceImpl> impl;
    };
} // namespace DnD5

#endif // DICE_H