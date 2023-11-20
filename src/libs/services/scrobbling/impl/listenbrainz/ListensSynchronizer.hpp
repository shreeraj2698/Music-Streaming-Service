

#pragma once

#include <optional>
#include <unordered_map>
#include <boost/asio/io_context.hpp>
#include <boost/asio/io_context_strand.hpp>
#include <boost/asio/steady_timer.hpp>

#include "services/database/Types.hpp"
#include "services/database/UserId.hpp"

#include "services/scrobbling/Listen.hpp"

namespace Database
{
	class Db;
}

namespace Http
{
	class IClient;
}

namespace Scrobbling::ListenBrainz
{
	class ListensSynchronizer
	{
		public:
			ListensSynchronizer(boost::asio::io_context& ioContext, Database::Db& db, Http::IClient& client);

			void enqueListen(const TimedListen& listen);
			void enqueListenNow(const Listen& listen);

		private:
			void enqueListen(const Listen& listen, const Wt::WDateTime& timePoint);
			bool saveListen(const TimedListen& listen, Database::ScrobblingState scrobblinState);

			void enquePendingListens();

			struct UserContext
			{
				UserContext(Database::UserId id) : userId {id} {}

				UserContext(const UserContext&) = delete;
				UserContext(UserContext&&) = delete;
				UserContext& operator=(const UserContext&) = delete;
				UserContext& operator=(UserContext&&) = delete;

				const Database::UserId		userId;
				bool						syncing {};
				std::optional<std::size_t>	listenCount {};

				// resetted at each sync
				std::string		listenBrainzUserName; // need to be resolved first
				Wt::WDateTime	maxDateTime;
				std::size_t		fetchedListenCount{};
				std::size_t		matchedListenCount{};
				std::size_t		importedListenCount{};
			};

			UserContext& getUserContext(Database::UserId userId);
			bool isSyncing() const;
			void scheduleSync(std::chrono::seconds fromNow);
			void startSync();
			void startSync(UserContext& context);
			void onSyncEnded(UserContext& context);
			void enqueValidateToken(UserContext& context);
			void enqueGetListenCount(UserContext& context);
			void enqueGetListens(UserContext& context);
			void processGetListensResponse(std::string_view body, UserContext& context);

			boost::asio::io_context&		_ioContext;
			boost::asio::io_context::strand	_strand {_ioContext};
			Database::Db&					_db;
			boost::asio::steady_timer		_syncTimer {_ioContext};
			Http::IClient&					_client;

			std::unordered_map<Database::UserId, UserContext> _userContexts;

			const std::size_t			_maxSyncListenCount;
			const std::chrono::hours	_syncListensPeriod;
	};
} // Scrobbling::ListenBrainz

