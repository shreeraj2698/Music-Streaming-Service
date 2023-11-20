

#pragma once

#include <mutex>
#include <unordered_set>
#include <unordered_map>

#include <Wt/WSignal.h>

#include "services/database/UserId.hpp"

namespace UserInterface
{
	class LmsApplication;
	class LmsApplicationManager
	{
		public:
			Wt::Signal<LmsApplication&> applicationRegistered;
			Wt::Signal<LmsApplication&> applicationUnregistered;

		private:
			friend class LmsApplication;

			void registerApplication(LmsApplication& application);
			void unregisterApplication(LmsApplication& application);

			std::mutex _mutex;
			std::unordered_map<Database::UserId, std::unordered_set<LmsApplication*>>  m_applications;
	};
} // UserInterface
