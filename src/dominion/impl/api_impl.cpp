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

#include "api_impl.h"

#include <boost/filesystem.hpp>

#include "character_impl.h"
#include "database_impl.h"
#include "perk_impl.h"
#include "skill_impl.h"
#include "style_impl.h"
#include "../database.h"

namespace Dominion
{
    ApiImpl::ApiImpl() :
        db_(std::make_shared<DatabaseImpl>())
    {}

    std::shared_ptr<DataBase> ApiImpl::database()
    {
        return std::make_shared<DataBase>(db_);
    }

    std::shared_ptr<Character> ApiImpl::CreateCharacter()
    {
        uint32_t guid = db_->GetCount<Character>() + 1;

        std::shared_ptr<CharacterImpl> impl = std::make_shared<CharacterImpl>(db_, guid);

        db_->AddData(impl);

        return std::make_shared<Character>(impl);
    }

    ApiImpl& ApiImpl::instance()
    {
        static ApiImpl instance;

        return instance;
    }

    void ApiImpl::LoadDatabase(const std::string& dataPath)
    {
        boost::filesystem::path path(dataPath);
        boost::filesystem::path file("dominion.db");
        boost::filesystem::path canonical = boost::filesystem::canonical(dataPath / file);

        canonical = canonical.make_preferred();

        if (boost::filesystem::exists(canonical)) {
            db_->ConnectDatabase(canonical);

            // create data structure from db_ info
            db_->ExecuteQuery("select * from perk", PerkImpl::LoadFromDB);
            db_->ExecuteQuery("select * from skill", SkillImpl::LoadFromDB);
            db_->ExecuteQuery("select * from style", StyleImpl::LoadFromDB);
        } else {
            throw std::invalid_argument("Invalid path to database");
        }
    }
} // namespace Dominion
