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

#ifndef CLASS_ID_UTILITY_H
#define CLASS_ID_UTILITY_H

#include <string>

#include "classid.h"
#include "character_impl.h"
#include "perk_impl.h"
#include "skill_impl.h"
#include "style_impl.h"
#include "../character/character.h"
#include "../character/perk.h"
#include "../character/skill.h"
#include "../character/style.h"

namespace Dominion
{
    template <typename T>
    class NextID
    {
    public:
        static void set_next(uint_fast32_t value)
        {
            if (value > next_)
                next_ = value;
        }

        static uint_fast32_t next()
        {
            ++next_;
            return next_;
        }

    private:
        static uint_fast32_t next_;
    };

    template <typename T>
    struct ClassIDUtility
    {};

    template <>
    class ClassIDUtility<CharacterImpl> : public NextID < CharacterImpl >
    {
    public:
        typedef CharacterImpl ImplType;
        typedef Character Type;
        static int ClassIDFromType() { return ClassID_Character; }
        static std::string SQLColumnName() { return std::string("character"); }
    };

    template <>
    struct ClassIDUtility<PerkImpl> : public NextID < PerkImpl >
    {
    public:
        typedef PerkImpl ImplType;
        typedef Perk Type;
        static int ClassIDFromType() { return ClassID_Perk; }
        static std::string SQLColumnName() { return std::string("perk"); }
    };

    template <>
    struct ClassIDUtility<SkillImpl> : public NextID < SkillImpl >
    {
    public:
        typedef SkillImpl ImplType;
        typedef Skill Type;
        static int ClassIDFromType() { return ClassID_Skill; }
        static std::string SQLColumnName() { return std::string("skill"); }
    };

    template <>
    struct ClassIDUtility<StyleImpl> : public NextID < StyleImpl >
    {
    public:
        typedef StyleImpl ImplType;
        typedef Style Type;
        static int ClassIDFromType() { return ClassID_Style; }
        static std::string SQLColumnName() { return std::string("style"); }
    };
} // namespace Dominion

#endif // CLASS_ID_UTILITY_H
