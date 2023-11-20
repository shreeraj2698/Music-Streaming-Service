

#pragma once

#include <memory>

#include "utils/IResourceHandler.hpp"
#include "utils/IZipper.hpp"

std::unique_ptr<IResourceHandler> createZipperResourceHandler(std::unique_ptr<Zip::IZipper> zipper);

