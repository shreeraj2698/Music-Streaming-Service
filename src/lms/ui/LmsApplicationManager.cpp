

#include "LmsApplicationManager.hpp"

#include "LmsApplication.hpp"

namespace UserInterface
{
	void
	LmsApplicationManager::registerApplication(LmsApplication& application)
	{
		{
			std::scoped_lock lock {_mutex};
			m_applications[application.getUserId()].insert(&application);
		}

		applicationRegistered.emit(application);
	}

	void
	LmsApplicationManager::unregisterApplication(LmsApplication& application)
	{
		{
			std::scoped_lock lock {_mutex};
			m_applications[application.getUserId()].erase(&application);
		}

		applicationUnregistered.emit(application);
	}

} // UserInterface
