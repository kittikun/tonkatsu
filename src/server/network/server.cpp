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

#include <boost/asio.hpp>

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
			boost::asio::io_service io_service;
			boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 4242);
			boost::asio::ip::tcp::acceptor acceptor(io_service, endpoint);

			LOGN << "Server thread started";

			running_.store(true);

			// Loop that accepts connections
			while (running_.load()) {
				// Can only connect one client at the time
				LOGN << "Waiting for connection";

				std::unique_ptr<boost::asio::ip::tcp::socket> socket(new boost::asio::ip::tcp::socket(io_service));

				auto g = [&](const boost::system::error_code &ec) {
					if (!ec) {
						LOGN << "Connection accepted";

						contextes_.push_back(std::move(Context(std::move(socket))));
					} else {
						LOGE << ec;
					}
				};

				acceptor.async_accept(*socket, g);
				io_service.run();
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