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

#ifndef PACKET_H
#define PACKET_H

#include <array>

namespace Tonkatsu
{
	namespace Network
	{
		const std::size_t PacketSize = 32;

		class Packet
		{
		public:

		private:
			std::array<char, PacketSize> data_;
			std::size_t size_;
		};
	} // namespace Network
} // namespace Tonkatsu

#endif // PACKET_H
