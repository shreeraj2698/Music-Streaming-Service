

#pragma once

#include <filesystem>
#include <memory>

#include "utils/IResourceHandler.hpp"

std::unique_ptr<IResourceHandler> createFileResourceHandler(const std::filesystem::path& path);

