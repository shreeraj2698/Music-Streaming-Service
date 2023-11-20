

#pragma once

#include <Wt/WDateTime.h>
#include <Wt/Dbo/Dbo.h>

#include "services/database/Object.hpp"
#include "services/database/ReleaseId.hpp"
#include "services/database/StarredReleaseId.hpp"
#include "services/database/Types.hpp"
#include "services/database/UserId.hpp"

namespace Database
{
	class Release;
	class Session;
	class User;

	class StarredRelease final : public Object<StarredRelease, StarredReleaseId>
	{
		public:
			StarredRelease() = default;

			// Search utility
			static std::size_t	getCount(Session& session);
			static pointer		find(Session& session, StarredReleaseId id);
			static pointer		find(Session& session, ReleaseId releaseId, UserId userId, Scrobbler scrobbler);

			// Accessors
			ObjectPtr<Release>	getRelease() const { return _release; }
			ObjectPtr<User>		getUser() const { return _user; }
			Scrobbler			getScrobbler() const { return _scrobbler; }
			const Wt::WDateTime& getDateTime() const { return _dateTime; }
			ScrobblingState		getScrobblingState() const { return _scrobblingState; }

			// Setters
			void setDateTime(const Wt::WDateTime& dateTime);
			void setScrobblingState(ScrobblingState state) { _scrobblingState  = state; }

			template<class Action>
			void persist(Action& a)
			{
				Wt::Dbo::field(a,	_scrobbler,			"scrobbler");
				Wt::Dbo::field(a,	_scrobblingState,	"scrobbling_state");
				Wt::Dbo::field(a,	_dateTime,			"date_time");

				Wt::Dbo::belongsTo(a,	_release,	"release",	Wt::Dbo::OnDeleteCascade);
				Wt::Dbo::belongsTo(a,	_user,		"user",		Wt::Dbo::OnDeleteCascade);
			}

		private:
			friend class Session;
			StarredRelease(ObjectPtr<Release> release, ObjectPtr<User> user, Scrobbler scrobbler);
			static pointer create(Session& session, ObjectPtr<Release> release, ObjectPtr<User> user, Scrobbler scrobbler);

			Scrobbler		_scrobbler;			// for which scrobbler
			ScrobblingState	_scrobblingState {ScrobblingState::PendingAdd};
			Wt::WDateTime	_dateTime;			// when it was starred

			Wt::Dbo::ptr<Release>	_release;
			Wt::Dbo::ptr<User>		_user;
	};
} // namespace Database

