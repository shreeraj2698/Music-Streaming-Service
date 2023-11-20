

#include "DirectoryValidator.hpp"

#include <filesystem>

namespace UserInterface
{
	class DirectoryValidator : public Wt::WValidator
	{
		private:
			Wt::WValidator::Result validate(const Wt::WString& input) const override;
			std::string javaScriptValidate() const override { return {}; }
	};

	Wt::WValidator::Result
	DirectoryValidator::validate(const Wt::WString& input) const
	{
		if (input.empty())
			return Wt::WValidator::validate(input);

		const std::filesystem::path p {input.toUTF8()};
		std::error_code ec;

		// TODO check rights
		bool res = std::filesystem::is_directory(p, ec);
		if (ec)
			return Wt::WValidator::Result(Wt::ValidationState::Invalid, ec.message()); // TODO translate common errors
		else if (res)
			return Wt::WValidator::Result(Wt::ValidationState::Valid);
		else
			return Wt::WValidator::Result(Wt::ValidationState::Invalid, Wt::WString::tr("Lms.not-a-directory"));
	}

	std::unique_ptr<Wt::WValidator>
	createDirectoryValidator()
	{
		return std::make_unique<DirectoryValidator>();
	}
} // namespace UserInterface
