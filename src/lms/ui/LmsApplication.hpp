

#pragma once

#include <optional>

#include <Wt/WApplication.h>

#include "services/database/Object.hpp"
#include "services/database/UserId.hpp"
#include "services/database/Types.hpp"
#include "services/scanner/ScannerEvents.hpp"
#include "Notification.hpp"

namespace Database
{
	class Db;
	class Session;
	class User;
}

namespace UserInterface {

class CoverResource;
class LmsApplicationException;
class MediaPlayer;
class PlayQueue;
class LmsApplicationManager;
class NotificationContainer;
class ModalManager;

class LmsApplication : public Wt::WApplication
{
	public:
		LmsApplication(const Wt::WEnvironment& env, Database::Db& db, LmsApplicationManager& appManager, std::optional<Database::UserId> userId = std::nullopt);
		~LmsApplication();

		static std::unique_ptr<Wt::WApplication> create(const Wt::WEnvironment& env, Database::Db& db, LmsApplicationManager& appManager);
		static LmsApplication* instance();

		// Session application data
		std::shared_ptr<CoverResource> getCoverResource() { return _coverResource; }
		Database::Db& getDb();
		Database::Session& getDbSession(); // always thread safe

		Database::ObjectPtr<Database::User>	getUser();
		Database::UserId				getUserId();
		bool isUserAuthStrong() const; // user must be logged in prior this call
		Database::UserType				getUserType(); // user must be logged in prior this call
		std::string						getUserLoginName(); // user must be logged in prior this call

		// Proxified scanner events
		Scanner::Events& getScannerEvents() { return _scannerEvents; }

		// Utils
		void post(std::function<void()> func);
		void setTitle(const Wt::WString& title = "");

		// Used to classify the message sent to the user
		void notifyMsg(Notification::Type type, const Wt::WString& category, const Wt::WString& message, std::chrono::milliseconds duration = std::chrono::milliseconds {5000});

		MediaPlayer&	getMediaPlayer() const { return *_mediaPlayer; }
		PlayQueue&		getPlayQueue() const { return *_playQueue; }
		ModalManager&	getModalManager() const { return *_modalManager; }

		// Signal emitted just before the session ends (user may already be logged out)
		Wt::Signal<>&	preQuit() { return _preQuit; }

	private:
		void init();
		void processPasswordAuth();
		void handleException(LmsApplicationException& e);
		void goHomeAndQuit();

		// Signal slots
		void logoutUser();
		void onUserLoggedIn();

		void notify(const Wt::WEvent& event) override;
		void finalize() override;

		void createHome();

		Database::Db&							_db;
		Wt::Signal<>							_preQuit;
		LmsApplicationManager&   				_appManager;
		Scanner::Events							_scannerEvents;
		struct UserAuthInfo
		{
			Database::UserId	userId;
			bool				strongAuth {};
		};
		std::optional<UserAuthInfo>				_authenticatedUser;
		std::shared_ptr<CoverResource>			_coverResource;
		MediaPlayer*							_mediaPlayer {};
		PlayQueue*								_playQueue {};
		NotificationContainer*					_notificationContainer {};
		ModalManager*							_modalManager {};
};


// Helper to get session instance
#define LmsApp	::UserInterface::LmsApplication::instance()

} // namespace UserInterface

