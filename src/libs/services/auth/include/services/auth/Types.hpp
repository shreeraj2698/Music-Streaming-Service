

#pragma once

#include <string>
#include "services/database/Types.hpp"
#include "utils/Exception.hpp"

namespace Auth
{
	class Exception : public ::LmsException
	{
		using LmsException::LmsException;
	};

	class NotImplementedException : public Exception
	{
		public:
			NotImplementedException() : Auth::Exception {"Not implemented"} {}
	};

	class UserNotFoundException : public Exception
	{
		public:
			UserNotFoundException() : Auth::Exception {"User not found"} {}
	};

	struct PasswordValidationContext
	{
		std::string loginName;
		Database::UserType userType;
	};

	class PasswordException : public Exception
	{
		public:
			using Exception::Exception;
	};

	class PasswordTooWeakException : public PasswordException
	{
		public:
			PasswordTooWeakException() : PasswordException {"Password too weak"} {}
	};

	class PasswordMustMatchLoginNameException : public PasswordException
	{
		public:
			PasswordMustMatchLoginNameException() : PasswordException {"Password must match login name"} {}
	};
}

