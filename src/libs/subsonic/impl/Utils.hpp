

#pragma once

#include <string>

namespace API::Subsonic::Utils
{
    void checkSetPasswordImplemented();
    std::string makeNameFilesystemCompatible(const std::string& name);
}