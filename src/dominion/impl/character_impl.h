// Copyright(C) 2014 kittikun
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// This work is compatible with the Dominion Rules role-playing system.To learn more about
// Dominion Rules, visit the Dominion Rules web site at <http://www.dominionrules.org>

#ifndef CHARACTER_IMPL_H
#define CHARACTER_IMPL_H

#include <memory>
#include <unordered_map>
#include <array>

#include "../definitions.h"

namespace Dominion
{
    class PerkImpl;
    class SkillImpl;
    class StyleImpl;

    class CharacterImpl
    {
        CharacterImpl(const CharacterImpl&) = delete;
        CharacterImpl& operator=(const CharacterImpl&) = delete;

    public:
        CharacterImpl();

        void SetStyle(uint32_t guid);

    public:
        AttributeArray attributes_;
        std::shared_ptr<PerkImpl> perk_;
        std::shared_ptr<StyleImpl> style_;
        std::unordered_map<uint32_t, std::shared_ptr<SkillImpl>> skills_;
        ERace race_;
        uint16_t ap_;
    };
} // namespace Dominion

#endif // CHARACTER_IMPL_H
