

#include "Utils.hpp"

#include "utils/Service.hpp"
#include "utils/String.hpp"
#include "services/auth/IPasswordService.hpp"
#include "SubsonicResponse.hpp"

namespace API::Subsonic::Utils
{
    void checkSetPasswordImplemented()
    {
        Auth::IPasswordService* passwordService{ Service<Auth::IPasswordService>::get() };
        if (!passwordService || !passwordService->canSetPasswords())
            throw NotImplementedGenericError{};
    }

    std::string makeNameFilesystemCompatible(const std::string& name)
    {
        return StringUtils::replaceInString(name, "/", "_");
    }

}