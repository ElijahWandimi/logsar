#include "logger.h"

#include <iostream>
#include <chrono>

namespace logsar {
    class LoggerImpl {
        public:
        LoggerImpl() = default;

        void log(const LogMessage& message) {
            std::cout << "[" << toString(message.level) <<"]"
                <<"[" << message.timestamp << "]"
                << ", Message: " << message.message << std::endl;
        }

        void info(std::string_view message) {
            LogMessage logMessage{
                LogLevel::INFO,
                std::chrono::system_clock::now(),
                message
            };

            log(logMessage);
        }
    };

    Logger::Logger() : impl_(std::make_unique<LoggerImpl>()) {}
    Logger::~Logger() = default;
    Logger &Logger::operator=(Logger&&) noexcept = default;


    void Logger::info(std::string_view message) {
        impl_ ->info(message);
    }
}