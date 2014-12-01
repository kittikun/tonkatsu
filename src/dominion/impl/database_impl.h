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

#ifndef DATABASE_IMPL
#define DATABASE_IMPL

#include <memory>
#include <unordered_map>
#include <boost/functional/hash.hpp>
#include <boost/filesystem.hpp>
#include <sqlite/sqlite3.h>

#include "../data.h"

namespace Dominion
{
    typedef int(*SQLiteCallback)(void*, int, char**, char**);

    class DatabaseImpl
    {
        DatabaseImpl(const DatabaseImpl&) = delete;
        DatabaseImpl& operator=(const DatabaseImpl&) = delete;

    public:
        DatabaseImpl();
        ~DatabaseImpl();

        void ConnectDatabase(boost::filesystem::path path);

        void AddData(std::shared_ptr<Data>);

        template <class T>
        std::vector<std::shared_ptr<T>> GetListAsOpaque(const std::string& query)
        {
            int rc;
            char *err = nullptr;
            std::vector<T> res{4};

            // very bad to pass this like this but there is also no point in passing
            // a pointer to a smart ptr :/
            rc = sqlite3_exec(dbConnection, query.c_str(), std::bind(&DatabaseImpl::MakeOpaque, this), nullptr, &err);

            if (rc) {
                throw std::runtime_error("Query returned with an error");
            }

            return res;
        }

        void ExecuteQuery(const std::string&, SQLiteCallback);

    private:
        void MakeOpaque(void*, int, char**, char**);

    private:
        std::unordered_map<uint32_t, std::shared_ptr<Data>> database_;
        sqlite3* dbConnection;
    };
} // namespace Dominion

#endif // DATABASE_IMPL
