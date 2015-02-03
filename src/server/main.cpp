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

#include <iostream>
#include <memory>

#include "dominion.h"
#include "network/server.h"
#include "utility/log.h"

int main(int, char**)
{
	std::shared_ptr<Tonkatsu::DominionLib> dominion{ new Tonkatsu::DominionLib() };
	std::shared_ptr<Tonkatsu::Network::Server> server{ new Tonkatsu::Network::Server() };

	Tonkatsu::Utility::Log::Initialize();
	dominion->Initialise();
	server->Start();

	//try
	//{
	//	boost::asio::io_service io_service;

	//	boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 4242));

	//	for (;;)
	//	{
	//		boost::asio::ip::tcp::socket socket(io_service);
	//		acceptor.accept(socket);

	//		std::string message = "hello world";

	//		boost::system::error_code ignored_error;
	//		boost::asio::write(socket, boost::asio::buffer(message), ignored_error);

	//		boost::asio::async_read(socket, )
	//	}
	//}
	//catch (std::exception& e)
	//{
	//	std::cerr << e.what() << std::endl;
	//}

	LOGC << "Hello World!";

#if defined(_WIN32)
	std::cin.get();
#endif

	server->Stop();

	return 0;
}