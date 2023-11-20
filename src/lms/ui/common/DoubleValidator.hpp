

#pragma once

#include <Wt/WValidator.h>

namespace UserInterface
{
	std::unique_ptr<Wt::WValidator> createDoubleValidator(double min, double max);
} // namespace UserInterface

