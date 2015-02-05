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

#ifndef CONTEXT_H
#define CONTEXT_H

#include <memory>
#include <utility>
#include <boost/asio.hpp>
#include <boost/uuid/uuid.hpp>

namespace Tonkatsu
{
	namespace Network
	{
		class Context
		{
			Context(const Context&) = delete;
			Context& operator=(const Context&) = delete;
			Context& operator=(Context&&) = delete;

		public:
			Context(std::unique_ptr<boost::asio::ip::tcp::socket> socket);
			Context(Context&& other);
			~Context();

		private:
			boost::uuids::uuid guid_;
			std::unique_ptr<boost::asio::ip::tcp::socket> socket_;
		};
	} // namespace Network
} // namespace Tonkatsu

#endif // CONTEXT_H
