
#pragma once

#include "utils/IConfig.hpp"

#include <libconfig.h++>

// Used to get config values from configuration files
class Config final : public IConfig
{
	public:
		Config(const std::filesystem::path& p);
		~Config() = default;

		Config(const Config&) = delete;
		Config& operator=(const Config&) = delete;
		Config(Config&&) = delete;
		Config& operator=(Config&&) = delete;

		// Default values are returned in case of setting not found
		std::string_view		getString(std::string_view setting, std::string_view def = "") override;
		void 					visitStrings(std::string_view setting, std::function<void(std::string_view)> _func, std::initializer_list<std::string_view> defs) override;
		std::filesystem::path	getPath(std::string_view setting, const std::filesystem::path& def = std::filesystem::path()) override;
		unsigned long	getULong(std::string_view setting, unsigned long def = 0) override;
		long		getLong(std::string_view setting, long def = 0) override;
		bool		getBool(std::string_view setting, bool def = false) override;

	private:

		libconfig::Config _config;
};

