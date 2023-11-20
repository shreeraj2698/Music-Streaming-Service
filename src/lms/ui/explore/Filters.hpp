

#pragma once

#include <vector>
#include <Wt/WContainerWidget.h>
#include <Wt/WSignal.h>
#include <Wt/WTemplate.h>

#include "services/database/ClusterId.hpp"

#include "Filters.hpp"

namespace UserInterface
{
	class Filters : public Wt::WTemplate
	{
		public:
			Filters();

			void add(Database::ClusterId clusterId);
			const std::vector<Database::ClusterId>& getClusterIds() const { return _clusterIds; }
			Wt::Signal<>& updated() { return _sigUpdated; }

		private:
			void showDialog();

			Wt::WContainerWidget *_filters;
			Wt::Signal<> _sigUpdated;
			std::vector<Database::ClusterId> _clusterIds;
	};
} // namespace UserInterface

