/*
 * Copyright (C) 2019 Emeric Poupon
 *
 * This file is part of LMS.
 *
 * LMS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LMS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LMS.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "utils/WtLogger.hpp"

#include <thread>
#include <sstream>
#include <Wt/WApplication.h>
#include <Wt/WLogger.h>

#include "utils/Logger.hpp"

namespace
{
    std::string to_string(std::thread::id id)
    {
        std::ostringstream oss;
        oss << id;
        return oss.str();
    }
}

void WtLogger::processLog(const Log& log)
{
    Wt::log(getSeverityName(log.getSeverity())) << Wt::WLogger::sep << to_string(std::this_thread::get_id()) << Wt::WLogger::sep << "[" << getModuleName(log.getModule()) << "]" << Wt::WLogger::sep << log.getMessage();
}
