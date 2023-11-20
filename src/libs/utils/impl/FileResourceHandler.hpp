

#pragma once

#include <filesystem>
#include "utils/IResourceHandler.hpp"

class FileResourceHandler final : public IResourceHandler
{
	public:
		FileResourceHandler(const std::filesystem::path& filePath);

	private:
		Wt::Http::ResponseContinuation* processRequest(const Wt::Http::Request& request, Wt::Http::Response& response) override;
		void abort() override {};

		static constexpr std::size_t _chunkSize {65536};

		std::filesystem::path	_path;
		::uint64_t				_beyondLastByte {};
		::uint64_t				_offset {};
};

