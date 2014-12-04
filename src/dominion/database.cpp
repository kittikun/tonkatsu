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

#include "database.h"

#include "character/perk.h"
#include "character/skill.h"
#include "character/style.h"

#include "impl/database_impl.h"

namespace Dominion
{
    DataBase::DataBase(const std::shared_ptr<DatabaseImpl>& impl) :
        impl_(impl)
    {}

    DataBase::~DataBase()
    {}

    std::vector<std::shared_ptr<Skill>> DataBase::GetSkills() const
    {
        return impl_->GetListAsOpaque<Skill>("select id from skill");
    }

    std::vector<std::shared_ptr<Style>> DataBase::GetStyles() const
    {
        return impl_->GetListAsOpaque<Style>("select id from style");
    }
} // namespace Dominion
