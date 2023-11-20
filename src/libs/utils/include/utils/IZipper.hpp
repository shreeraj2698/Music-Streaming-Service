

#pragma once

#include <filesystem>
#include <memory>
#include <vector>

#include "Exception.hpp"

namespace Zip
{
	struct Entry
	{
		std::string fileName;
		std::filesystem::path filePath;
	};
	using EntryContainer = std::vector<Entry>;

	class Exception : public LmsException
	{
		using LmsException::LmsException;
	};

	class IZipper
	{
		public:
			virtual ~IZipper() = default;

			virtual std::uint64_t writeSome(std::ostream& output) = 0;
			virtual bool isComplete() const = 0;
			virtual void abort() = 0;
	};

	std::unique_ptr<IZipper> createArchiveZipper(const EntryContainer& entries);
} // namespace Zip

