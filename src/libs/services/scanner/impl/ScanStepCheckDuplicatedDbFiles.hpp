

#pragma once

#include "ScanStepBase.hpp"

namespace Scanner
{
	class ScanStepCheckDuplicatedDbFiles : public ScanStepBase
	{
		public:
			using ScanStepBase::ScanStepBase;

		private:
			std::string_view getStepName() const override { return "Checking for duplicated files"; }
			ScanStep getStep() const override { return ScanStep::CheckingForDuplicateFiles; }
			void process(ScanContext& context) override;
	};
}
