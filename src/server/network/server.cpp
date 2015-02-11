// Copyright(C) 2015 kittikun
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

#include "session.h"
#include "../utility/log.h"

namespace Tonkatsu
{
	Server::Server()
		: io_service_()
		, acceptor_(io_service_, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 4242))
	{
	}

	void Server::Handler_Accept(Session* session, const boost::system::error_code& ec)
	{
		if (!ec) {
			LOGN << "Connection accepted";

			session->Open();
			mapSessions_.insert(std::make_pair(session->guid(), std::unique_ptr < Session > {session}));
			//sessions_.push_back(session);
			StartAccept();
		} else {
			LOGE << ec.message();
		}
	}

	void Server::RequestCloseSesion(boost::uuids::uuid guid)
	{
		auto item = mapSessions_.find(guid);

		if (item != std::end(mapSessions_)) {
			item->second->Close();
			mapSessions_.erase(guid);
		}
	}

	void Server::Start()
	{
		StartAccept();
	}

	void Server::StartAccept()
	{
		// Can only connect one client at the time
		Session* session = new Session(io_service_, shared_from_this());

		boost::system::error_code ec;

		LOGN << "Waiting for connection";

		acceptor_.async_accept(session->socket(), std::bind(&Server::Handler_Accept, this, session, std::placeholders::_1));
		io_service_.run(ec);

		if (ec)
			LOGE << ec.message();
	}

	void Server::Stop()
	{
		io_service_.stop();

		for (auto& pair : mapSessions_)
			pair.second->Close();

		mapSessions_.clear();

		LOGN << "Server shutdown";
	}
} // namespace Tonkatsu // namespace Tonkatsu