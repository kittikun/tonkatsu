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

#include <unordered_map>
#include <boost/shared_ptr.hpp>
#include <boost/functional/hash.hpp>

#include "data.h"

namespace Dominion
{
	class DataBase::DatabaseImpl
	{
	public:
		DatabaseImpl(const DatabaseImpl&) = delete;
		DatabaseImpl& operator=(const DatabaseImpl&) = delete;

		DatabaseImpl()
		{

		}

	private:
		std::unordered_map<boost::uuids::uuid, boost::shared_ptr<Data>, boost::hash<boost::uuids::uuid>> database_;
	};

	//----------------------------------------------------------------------------------------------
	// ABILITIES
	//----------------------------------------------------------------------------------------------
	DataBase::DataBase() :
		impl_(new DatabaseImpl())
	{
	}

	DataBase::~DataBase()
	{
	}

} // namespace Dominion