

#pragma once

#include "utils/Exception.hpp"

namespace Scrobbling
{
    class Exception : public LmsException
    {
    public:
        using LmsException::LmsException;
    };
}
