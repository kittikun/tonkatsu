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

#include "app.h"

#include <functional>
#include <thread>

#include "utility/log.h"

#if defined(_WIN32)
#include <windows.h>

std::function<void()> func;

BOOL WINAPI console_ctrl_handler(DWORD signal)
{
	if (signal == CTRL_C_EVENT) {
		LOGC << "Ctrl-C detected";
		func();
	}

	return TRUE;
}
#endif // _WIN32

namespace Tonkatsu
{
	Application::Application()
		: dominion_{ new DominionLib() }
		, server_{ new Network::Server() }
	{
		Tonkatsu::Utility::Log::Initialize();

#if defined(_WIN32)
		func = std::bind(&Application::Quit, this);

		if (!SetConsoleCtrlHandler(console_ctrl_handler, TRUE)) {
			LOGE << "\nERROR: Could not set control handler";
		}
#endif // _WIN32
	}

	void Application::Run()
	{
		dominion_->Initialise();
		server_->Start();

		LOGC << "Tonkatsu Server v0.0";

		running_.store(true);

		while (running_.load())
		{
			std::this_thread::yield();
		}
	}

	void Application::Quit()
	{
		server_->Stop();
		running_.store(false);
	}
} // namespace Tonkatsu