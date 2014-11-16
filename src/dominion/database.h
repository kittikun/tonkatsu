// Copyright(C) 2014 kittikun
//
// This program is free software : you can redistribute it and / or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.If not, see <http://www.gnu.org/licenses/>.
//
// This work is compatible with the Dominion Rules role-playing system.To learn more about
// Dominion Rules, visit the Dominion Rules web site at <http://www.dominionrules.org>

#ifndef DATABASE_H
#define DATABASE_H

#include <memory>

#include "platform.h"

namespace Dominion
{
	class KATSU_API DataBase 
	{
	public:
		DataBase::DataBase();
		DataBase::~DataBase();

		DataBase(const DataBase&) = delete;
		DataBase& operator=(const DataBase&) = delete;

		DataBase& DataBase::getInstance() {
			static DataBase instance;

			return instance;
		}

	private:
		class DatabaseImpl;
		std::unique_ptr<DatabaseImpl> impl_;
	};
}

#endif // DATABASE_H