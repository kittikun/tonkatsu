//  Copyright (C) 2013  kittikun
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along
//  with this program; if not, write to the Free Software Foundation, Inc.,
//  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

#include "log.h"

#include <iostream>
#include <boost/date_time.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/debug_output_backend.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sinks/basic_sink_backend.hpp>

namespace attrs = boost::log::attributes;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;
namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;

namespace Tonkatsu
{
	namespace Core
	{
		namespace Log
		{
			BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", ELogLevel);

			std::ostream& operator<<(std::ostream& strm, ELogLevel level)
			{
				static const char* strings[] =
				{
					"core",
					"WARNING",
					"ERROR",
				};

				if (static_cast<std::size_t>(level) < sizeof(strings) / sizeof(*strings))
					strm << strings[level];
				else
					strm << static_cast<int>(level);

				return strm;
			}

			void Initialize()
			{
				logging::add_console_log(std::cout, keywords::format = expr::format("%1%: [%2%] %3%")
					% expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%H:%M:%S")
					% severity
					% expr::message);

				logging::add_common_attributes();

#if defined(_WIN32)
				boost::shared_ptr<logging::core> core = logging::core::get();
				boost::shared_ptr<sinks::synchronous_sink< sinks::debug_output_backend>> debugSink(new sinks::synchronous_sink<sinks::debug_output_backend>());

				debugSink->set_filter(expr::is_debugger_present());
				debugSink->set_formatter(expr::format("%1%: [%2%] %3%\n")
					% expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%H:%M:%S")
					% severity
					% expr::message);

				core->add_sink(debugSink);
#endif
			}
		} // namespace Log
	} // namespace Core
} // namespace Tonkatsu