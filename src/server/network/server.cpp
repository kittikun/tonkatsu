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

#include "server.h"

#include <functional>

#include "../utility/log.h"

namespace Tonkatsu
{
	namespace Network
	{
		Server::Server()
		{
		}

		void Server::Main()
		{
			LOGN << "Server thread started";

			running_.store(true);

			while (running_.load()) {
			}

			int i = 0;
		}

		void Server::Start()
		{
			thread_.reset(new std::thread(std::bind(&Server::Main, this)));
		}

		void Server::Stop()
		{
			running_.store(false);
			thread_->join();
		}
	} // namespace Network
} // namespace Tonkatsu // namespace Tonkatsu