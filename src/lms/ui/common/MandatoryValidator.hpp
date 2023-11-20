

#pragma once

#include <Wt/WValidator.h>

namespace UserInterface
{
	std::unique_ptr<Wt::WValidator> createMandatoryValidator();
} // namespace UserInterface

