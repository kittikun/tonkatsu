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

#ifndef SERVER_H
#define SERVER_H

#include <memory>
#include <unordered_map>
#include <boost/asio.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/functional/hash.hpp>

namespace Tonkatsu
{
	class Session;

	class Server : public std::enable_shared_from_this < Server >
	{
		Server(const Server&) = delete;
		Server& operator=(const Server&) = delete;
		Server(Server&&) = delete;
		Server& operator=(Server&&) = delete;
	public:
		Server();

		void Start();
		void Stop();

		// Sessions will request to be closed on error
		void RequestCloseSesion(boost::uuids::uuid);

	private:
		void StartAccept();
		void Handler_Accept(Session*, const boost::system::error_code&);

	private:
		using SessionMap = std::unordered_map < boost::uuids::uuid, std::unique_ptr<Session>, boost::hash<boost::uuids::uuid> > ;

		boost::asio::io_service io_service_;
		boost::asio::ip::tcp::acceptor acceptor_;
		SessionMap mapSessions_;
	};
} // namespace Tonkatsu

#endif // SERVER_H
