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

#include "../utility/log.h"

namespace Tonkatsu
{
	namespace Network
	{
		Server::Server()
			: io_service_()
			, acceptor_(io_service_, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 4242))
		{
		}

		void Server::Main()
		{
			LOGN << "Server thread started";

			running_.store(true);

			// Loop that accepts connections
			while (running_.load()) {
				// Can only connect one client at the time
				Session session(io_service_);
				boost::system::error_code ec;

				LOGN << "Waiting for connection";

				auto g = [&](const boost::system::error_code &ec) {
					if (!ec) {
						LOGN << "Connection accepted";

						session.open();
						sessions_.push_back(std::move(session));
					} else {
						LOGE << ec.message();
					}
				};

				acceptor_.async_accept(session.socket(), g);
				io_service_.reset();
				io_service_.run(ec);

				if (ec)
					LOGE << ec.message();
			}

			int i = 0;
		}

		void Server::Start()
		{
			thread_.reset(new std::thread(std::bind(&Server::Main, this)));
		}

		void Server::Stop()
		{
			if (running_.load()) {
				running_.store(false);
				io_service_.stop();

				for (auto& session : sessions_)
					session.close();

				thread_->join();
				LOGN << "Server shutdown";
			}
		}
	} // namespace Network
} // namespace Tonkatsu // namespace Tonkatsu