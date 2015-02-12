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

#ifndef APP_H
#define APP_H

#include <atomic>
#include <memory>

namespace Tonkatsu
{
	class DominionLib;
	class Server;

	class Application
	{
		Application(const Application&) = delete;
		Application& operator=(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator=(Application&&) = delete;

	public:
		Application();

		void Run();
		void Quit();

	private:
		std::atomic<bool> running_;
		std::unique_ptr<DominionLib> dominion_;
		std::shared_ptr<Server> server_;
	};
} // namespace Tonkatsu

#endif // APP_H