#pragma once
#include "pch.hpp"

namespace AstaStar
{
    class Logger
    {
    public:
        static void init();

        static std::shared_ptr<spdlog::logger>& getLogger();
    private:
        static std::shared_ptr<spdlog::logger> m_Logger;
    };

    #define AS_TRACE(...)			::AstaStar::Logger::getLogger()->trace(__VA_ARGS__)
    #define AS_DEBUG(...)			::AstaStar::Logger::getLogger()->debug(__VA_ARGS__)
	#define AS_INFO(...)			::AstaStar::Logger::getLogger()->info(__VA_ARGS__)
	#define AS_WARN(...)			::AstaStar::Logger::getLogger()->warn(__VA_ARGS__)
	#define AS_ERROR(...)			::AstaStar::Logger::getLogger()->error(__VA_ARGS__)
	#define AS_CRITICAL(...)		::AstaStar::Logger::getLogger()->critical(__VA_ARGS__)

} // namespace AstaStar
