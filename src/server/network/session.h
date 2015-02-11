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
#include <deque>
#include <boost/asio.hpp>
#include <boost/uuid/uuid.hpp>

namespace Tonkatsu
{
	enum class PaquetType : uint8_t;
	class Server;

	struct Paquet
	{
		PaquetType type;
	};

	class Session
	{
		static const std::size_t BUFFER_MAX_SIZE = 32;

		Session(const Session&) = delete;
		Session& operator=(const Session&) = delete;
		Session& operator=(Session&&) = delete;

	public:
		Session(boost::asio::io_service&, std::weak_ptr<Server>);
		Session(Session&& other);

		void Open();
		void Close();

		void Read();
		//void WriteString(const std::string& str);

		boost::asio::ip::tcp::socket& socket() { return socket_; }
		boost::uuids::uuid guid() const { return guid_; }

	private:
		enum class State : uint8_t
		{
			// Expect to receive a header to describe the incoming data
			Header,
			Hanshaking
		};

		bool CheckMagic();
		void Handle_Write(const boost::system::error_code&, size_t);
		void Handle_Read(const boost::system::error_code&, size_t);

	private:
		State state_;
		boost::uuids::uuid guid_;
		boost::asio::ip::tcp::socket socket_;
		std::array<uint8_t, BUFFER_MAX_SIZE> buffer_;
		std::deque<Paquet> sendQueue_;
		std::weak_ptr<Server> server_;
	};
} // namespace Tonkatsu

#endif // SESSION_H
