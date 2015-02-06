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

#include "Session.h"

#include <boost/format.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "../utility/log.h"

namespace Tonkatsu
{
	namespace Network
	{
		Session::Session(boost::asio::io_service& io_service)
			: socket_(io_service)
			, guid_(boost::uuids::random_generator()())
		{
		}

		Session::Session(Session&& other)
			: socket_(std::move(other.socket_))
			, guid_(std::move(other.guid_))
		{
		}

		void Session::open()
		{
			boost::format fmt = boost::format("Connection accepted, id: %1%") % guid_;
			LOGN << boost::str(fmt);

			WriteString("hello world");
		}

		void Session::close()
		{
			boost::system::error_code ec;
			socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);

			if (ec)
				LOGE << ec.message();

			socket_.close(ec);

			if (ec)
				LOGE << ec.message();
		}

		void Session::WriteString(const std::string& str)
		{
			boost::asio::async_write(socket_,
				boost::asio::buffer(data_, str.size()),
				boost::bind(&Session::CallbackWrite, this, boost::asio::placeholders::error));
		}

		void Session::CallbackWrite(const boost::system::error_code& ec)
		{
			if (ec)
				LOGE << ec.message();
		}
	} // namespace Network
} // namespace Tonkatsu