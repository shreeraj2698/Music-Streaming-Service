

#pragma once

#include <string>
#include <optional>
#include <boost/asio/io_context.hpp>

#include "IScrobbler.hpp"
#include "FeedbacksSynchronizer.hpp"
#include "ListensSynchronizer.hpp"

namespace Database
{
	class Db;
}

namespace Scrobbling::ListenBrainz
{
	class Scrobbler final : public IScrobbler
	{
		public:
			Scrobbler(boost::asio::io_context& ioContext, Database::Db& db);
			~Scrobbler();

			Scrobbler(const Scrobbler&) = delete;
			Scrobbler(const Scrobbler&&) = delete;
			Scrobbler& operator=(const Scrobbler&) = delete;
			Scrobbler& operator=(const Scrobbler&&) = delete;

		private:
			void listenStarted(const Listen& listen) override;
			void listenFinished(const Listen& listen, std::optional<std::chrono::seconds> duration) override;
			void addTimedListen(const TimedListen& listen) override;

			// Submit listens
			void enqueListen(const Listen& listen, const Wt::WDateTime& timePoint);

			// Star
			void onStarred(Database::StarredArtistId starredArtistId) override;
			void onUnstarred(Database::StarredArtistId starredArtistId) override;
			void onStarred(Database::StarredReleaseId starredReleaseId) override;
			void onUnstarred(Database::StarredReleaseId starredReleaseId) override;
			void onStarred(Database::StarredTrackId starredTrackId) override;
			void onUnstarred(Database::StarredTrackId starredTrackId) override;

			boost::asio::io_context&		_ioContext;
			Database::Db&					_db;
			std::string						_baseAPIUrl;
			std::unique_ptr<Http::IClient>	_client;
			ListensSynchronizer				_listensSynchronizer;
			FeedbacksSynchronizer			_feedbacksSynchronizer;
	};
} // Scrobbling::ListenBrainz

