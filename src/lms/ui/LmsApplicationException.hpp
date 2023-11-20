

#pragma once

#include "services/database/Types.hpp"
#include "utils/Exception.hpp"

namespace UserInterface
{
	class LmsApplicationException : public LmsException
	{
		public:
			LmsApplicationException(const Wt::WString& error) : LmsException {error.toUTF8()} {}
	};

	class ArtistNotFoundException : public LmsApplicationException
	{
		public:
			ArtistNotFoundException() : LmsApplicationException {Wt::WString::tr("Lms.Error.artist-not-found")} {}
	};

	class ReleaseNotFoundException : public LmsApplicationException
	{
		public:
			ReleaseNotFoundException() : LmsApplicationException {Wt::WString::tr("Lms.Error.release-not-found")} {}
	};

	class TrackListNotFoundException : public LmsApplicationException
	{
		public:
			TrackListNotFoundException() : LmsApplicationException {Wt::WString::tr("Lms.Error.tracklist-not-found")} {}
	};

	class UserNotFoundException : public LmsApplicationException
	{
		public:
			UserNotFoundException() : LmsApplicationException {Wt::WString::tr("Lms.Error.user-not-found")} {}
	};

	class UserNotAllowedException : public LmsApplicationException
	{
		public:
			UserNotAllowedException() : LmsApplicationException {Wt::WString::tr("Lms.Error.user-not-allowed")} {}
	};
} // ns UserInterface
