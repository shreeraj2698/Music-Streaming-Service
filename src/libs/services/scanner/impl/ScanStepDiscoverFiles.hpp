

#pragma once

#include "ScanStepBase.hpp"

namespace Scanner
{
	class ScanStepDiscoverFiles : public ScanStepBase
	{
		public:
			using ScanStepBase::ScanStepBase;

		private:
			ScanStep getStep() const override { return ScanStep::DiscoveringFiles; }
			std::string_view getStepName() const override { return "DiscoveringFiles"; }
			void process(ScanContext& context) override;
	};
}
