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

#ifndef SESSION_H
#define SESSION_H

#include <array>
#include <cstdint>
#include <memory>
#include <utility>
#include <boost/asio.hpp>
#include <boost/uuid/uuid.hpp>

namespace Tonkatsu
{
	namespace Network
	{
		class Session
		{
			static const std::size_t PacketSize = 32;

			Session(const Session&) = delete;
			//Session(Session&&) = delete;
			Session& operator=(const Session&) = delete;
			Session& operator=(Session&&) = delete;

		public:
			Session(boost::asio::io_service& io_service);
			Session(Session&& other);

			void open();
			void close();

			void WriteString(const std::string& str);
			void CallbackWrite(const boost::system::error_code& error);

			boost::asio::ip::tcp::socket& socket() { return socket_; }

		private:
			boost::uuids::uuid guid_;
			boost::asio::ip::tcp::socket socket_;
			std::array<uint8_t, PacketSize> data_;
		};
	} // namespace Network
} // namespace Tonkatsu

#endif // SESSION_H
