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
#include <tuple>
#include <unordered_map>
#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/functional/hash.hpp>
#include <boost/filesystem.hpp>
#include <sqlite/sqlite3.h>

#include "../data.h"
#include "utility.h"

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
		std::vector<std::shared_ptr<T>> GetListAsOpaque()
		{
			typedef std::unordered_map<uint32_t, std::shared_ptr<Data>> DictionaryType;
			typedef std::vector<std::shared_ptr<T>> ResultType;
			typedef std::tuple<DictionaryType&, ResultType&> TupleType;

			int rc;
			char *err = nullptr;
			ResultType res;

			// lambda with capture cannot be passed as __cdecl so we have to resort to tuple usage
			TupleType tuple = std::tie(database_, res);

			auto f = [](void* data, int argc, char** argv, char**sdf) {
				TupleType* tuple = static_cast<TupleType*>(data);

				std::get<1>(*tuple).reserve(argc);

				for (int i = 0; i < argc; ++i) {
					int index = Utility<T>::ClassIDFromType() + boost::lexical_cast<int>(argv[i]);
					std::get<1>(*tuple).push_back(std::make_shared<T>(std::static_pointer_cast<Utility<T>::ImplType>(std::get<0>(*tuple)[index])));
				}

				return 0;
			};

			boost::format fmt = boost::format("select id from %1%") % Utility<T>::SQLColumnName();
			std::string query = boost::str(fmt);

			rc = sqlite3_exec(dbConnection, query.c_str(), f, static_cast<void*>(&tuple), &err);

			if (rc) {
				throw std::runtime_error("Query returned with an error");
			}

			return res;
		}

		void ExecuteQuery(const std::string&, SQLiteCallback);

	private:
		std::unordered_map<uint32_t, std::shared_ptr<Data>> database_;
		sqlite3* dbConnection;
	};
} // namespace Dominion

#endif // DATABASE_IMPL
