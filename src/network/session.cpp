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

#include "session.h"

#include <boost/format.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "definitions.h"
#include "server.h"
#include "../utility/log.h"

namespace Tonkatsu
{
	Session::Session(boost::asio::io_service& io_service, std::weak_ptr<Server> server)
		: socket_{ io_service }
		, state_{ State::Header }
		, guid_(boost::uuids::random_generator()())
		, server_{ server }
	{
	}

	Session::Session(Session&& other)
		: socket_{ std::move(other.socket_) }
		, buffer_(std::move(other.buffer_))
		, guid_(std::move(other.guid_))
	{
	}

	void Session::Open()
	{
		boost::format fmt = boost::format("Session id: %1%") % guid_;
		LOGN << boost::str(fmt);

		// wait for client handshake
		Read();
	}

	void Session::Close()
	{
		boost::system::error_code ec;
		socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);

		if (ec)
			LOGE << ec.message();

		socket_.close(ec);

		if (ec)
			LOGE << ec.message();
	}

	//void Session::WriteString(const std::string& str)
	//{
	//	std::ostream os(&data_);
	//	os << str;

	//	boost::asio::async_write(socket_,
	//		data_,
	//		std::bind(&Session::Handle_Write, this, std::placeholders::_1, std::placeholders::_2));
	//}

	void Session::Handle_Read(const boost::system::error_code& ec, size_t transferred)
	{
		if (!ec) {
			boost::format fmt = boost::format("Received %1% bytes") % transferred;
			LOGN << boost::str(fmt);

			// check for magic
			uint32_t magic = buffer_[3] << 24 | buffer_[2] << 16 | buffer_[1] << 8 | buffer_[0];

			if (magic == gMagic) {
				PaquetType type = static_cast<PaquetType>(buffer_[5]);

				if (type == PaquetType::Handshake) {
					state_ = State::Hanshaking;

					int count = 0;

					// write magic into buffer
					std::copy(reinterpret_cast<const uint8_t*>(&gMagic),
						reinterpret_cast<const uint8_t*>(&gMagic) + sizeof(gMagic),
						buffer_.data());
					count += sizeof(gMagic);

					// write packet type
					buffer_[count] = static_cast<uint8_t>(PaquetType::Handshake);
					++count;

					// append uuid
					std::copy(reinterpret_cast<const uint8_t*>(&guid_), reinterpret_cast<const uint8_t*>(&guid_) + sizeof(guid_), buffer_.data() + count);
					count += sizeof(guid_);

					boost::asio::async_write(socket_,
						boost::asio::buffer(buffer_, buffer_.size()),
						std::bind(&Session::WriteCompletionCondition, this, std::placeholders::_1, std::placeholders::_2),
						std::bind(&Session::Handle_Write, this, std::placeholders::_1, std::placeholders::_2));
				}
			} else {
				LOGE << "Received data doesn't validate magic";
				server_.lock()->RequestCloseSesion(guid_);
			}
		} else {
			LOGE << ec.message();
		}
	}

	void Session::Handle_Write(const boost::system::error_code& ec, size_t transferred)
	{
		if (!ec) {
			boost::format fmt = boost::format("Send %1% bytes") % transferred;
			LOGN << boost::str(fmt);
		} else {
			LOGE << ec.message();
		}
	}

	void Session::Read()
	{
		// read magic +  header
		boost::asio::async_read(socket_,
			boost::asio::buffer(buffer_.data(), buffer_.size()),
			std::bind(&Session::ReadCompletionCondition, this, std::placeholders::_1, std::placeholders::_2),
			std::bind(&Session::Handle_Read, this, std::placeholders::_1, std::placeholders::_2));
	}

	size_t Session::ReadCompletionCondition(const boost::system::error_code& ec, size_t transferred)
	{
		if (ec) {
			LOGE << ec.message();
		}

		if (state_ == State::Header)
		{
			if (transferred == 5)
				return 0;
		}

		return 1;
	}

	size_t Session::WriteCompletionCondition(const boost::system::error_code& ec, size_t transferred)
	{
		if (ec) {
			LOGE << ec.message();
		}

		if (state_ == State::Hanshaking)
		{
			if (transferred == 21)
				return 0;
		}

		return 1;
	}
} // namespace Tonkatsu