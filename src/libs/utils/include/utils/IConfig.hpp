
#pragma once

#include <filesystem>
#include <functional>
#include <string_view>

// Used to get config values from configuration files
class IConfig
{
	public:
		virtual ~IConfig() = default;

		// Default values are returned in case of setting not found
		virtual std::string_view		getString(std::string_view setting, std::string_view def = "") = 0;
		virtual void					visitStrings(std::string_view setting, std::function<void(std::string_view)> _func, std::initializer_list<std::string_view> def = {}) = 0;
		virtual std::filesystem::path	getPath(std::string_view setting, const std::filesystem::path& def = std::filesystem::path()) = 0;
		virtual unsigned long			getULong(std::string_view setting, unsigned long def = 0) = 0;
		virtual long					getLong(std::string_view setting, long def = 0) = 0;
		virtual bool					getBool(std::string_view setting, bool def = false) = 0;
};


std::unique_ptr<IConfig> createConfig(const std::filesystem::path& p);

