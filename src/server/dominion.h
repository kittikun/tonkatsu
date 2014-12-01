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

#ifndef DOMINION_H
#define DOMINION_H

#include <memory>

#include <dominion/database.h>

namespace Tonkatsu
{
    class DominionLib
    {
        DominionLib(const DominionLib&) = delete;
        DominionLib& operator=(const DominionLib&) = delete;

    public:
        DominionLib() {};

        void Initialise();

    private:
        std::shared_ptr<Dominion::DataBase> db_;
    };
} // namespace Tonkatsu

#endif DOMINION_H
