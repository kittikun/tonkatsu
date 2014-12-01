﻿//  Copyright (C) 2013  kittikun
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

#ifndef LOG_H
#define LOG_H

#include <boost/format.hpp>
#include <boost/log/expressions/keyword.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sources/severity_logger.hpp>

#define LOGC BOOST_LOG_SEV(Tonkatsu::Utility::Log::boost_log::get(), Tonkatsu::Utility::Log::Log_Core)
#define LOGD BOOST_LOG_SEV(Tonkatsu::Utility::Log::boost_log::get(), Tonkatsu::Utility::Log::Log_Dominion)
#define LOGW BOOST_LOG_SEV(Tonkatsu::Utility::Log::boost_log::get(), Tonkatsu::Utility::Log::Log_Warning)
#define LOGE BOOST_LOG_SEV(Tonkatsu::Utility::Log::boost_log::get(), Tonkatsu::Utility::Log::Log_Error)

namespace Tonkatsu
{
    namespace Utility
    {
        namespace Log
        {
            enum ELogLevel
            {
                Log_Core,
                Log_Dominion,
                Log_Warning,
                Log_Error
            };

            BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(boost_log, boost::log::sources::severity_logger_mt<ELogLevel>);

            void Initialize();
        } // namespace Log
    } // namespace Utility
} // namespace Tonkatsu

#endif // LOG_H
