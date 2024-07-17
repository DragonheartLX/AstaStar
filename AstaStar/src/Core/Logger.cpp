#include "AstaStar/Core/Logger.hpp"

#include <memory>
#include <spdlog/logger.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace AstaStar
{
    std::shared_ptr<spdlog::logger> Logger::m_Logger;

	void Logger::init()
	{
		std::vector<spdlog::sink_ptr> logSinks;
		logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		// logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("AstaStar.log", true));

		logSinks[0]->set_pattern("%^[%T] %n: %v%$");
		// logSinks[1]->set_pattern("[%T] [%l] %n: %v");

		m_Logger = std::make_shared<spdlog::logger>("AstaStar", begin(logSinks), end(logSinks));
		spdlog::register_logger(m_Logger);
		m_Logger->set_level(spdlog::level::trace);
		m_Logger->flush_on(spdlog::level::trace);
	}

	std::shared_ptr<spdlog::logger>& Logger::getLogger()
	{
		return m_Logger;
	}

} // namespace AstaStar
