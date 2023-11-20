

#pragma once

#include <filesystem>
#include <functional>
#include <string>
#include <vector>

#include <Wt/WDateTime.h>

namespace PathUtils
{
	std::uint32_t computeCrc32(const std::filesystem::path& p);

	// Make sure the given path is a directory
	// Create it if needed
	bool ensureDirectory(const std::filesystem::path& dir);

	// Get the last write time since Epoch
	Wt::WDateTime getLastWriteTime(const std::filesystem::path& dir);

	// returns false if aborted by user
	bool exploreFilesRecursive(const std::filesystem::path& directory, std::function<bool(std::error_code, const std::filesystem::path&)> cb, const std::filesystem::path* excludeDirFileName = {});

	// Check if file's extension is one of provided extensions
	bool hasFileAnyExtension(const std::filesystem::path& file, const std::vector<std::filesystem::path>& extensions);

	// Check if a path is within a directory (excludeDirFileName is a relative can be used to exclude a whole directory and its subdirectory, must not have parent_path)
	bool isPathInRootPath(const std::filesystem::path& path, const std::filesystem::path& rootPath, const std::filesystem::path* excludeDirFileName = {});


}
