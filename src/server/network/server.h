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

#ifndef SERVER_H
#define SERVER_H

#include <memory>
#include <thread>
#include <atomic>
#include <vector>
#include <boost/asio.hpp>

#include "session.h"

namespace Tonkatsu
{
	namespace Network
	{
		class Server
		{
			Server(const Server&) = delete;
			Server& operator=(const Server&) = delete;
			Server(Server&&) = delete;
			Server& operator=(Server&&) = delete;
		public:
			Server();

			void Start();
			void Stop();

		private:
			void Main();

		private:
			boost::asio::io_service io_service_;
			boost::asio::ip::tcp::acceptor acceptor_;
			std::unique_ptr<std::thread> thread_;
			std::atomic<bool> running_;
			std::vector<Session> sessions_;
		};
	} // namespace Network
} // namespace Tonkatsu

#endif // SERVER_H
