#include "classid_utility.h"

namespace Dominion
{
    template<> uint_fast32_t NextID<CharacterImpl>::next_;
    template<> uint_fast32_t NextID<PerkImpl>::next_;
    template<> uint_fast32_t NextID<SkillImpl>::next_;
    template<> uint_fast32_t NextID<StyleImpl>::next_;
} // namespace Dominion
