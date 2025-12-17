#include "logger.h"

#include <iostream>
#include <chrono>

namespace logsar {
    class LoggerImpl {
        private:
        void log(const LogMessage& message) {
            std::cout << "[" << toString(message.level) <<"]"
                <<"[" << message.timestamp << "]"
                << ", Message: " << message.message << std::endl;
        }

        public:
        LoggerImpl() = default;

        void info(std::string_view message) {
            LogMessage logMessage{
                LogLevel::INFO,
                std::chrono::system_clock::now(),
                message
            };

            log(logMessage);
        }

        void debug(std::string_view message) {
            LogMessage logMessage{
                LogLevel::DEBUG,
                std::chrono::system_clock::now(),
                message
            };

            log(logMessage);
        }

        void error(std::string_view message) {
            LogMessage logMessage{
                LogLevel::ERROR,
                std::chrono::system_clock::now(),
                message
            };

            log(logMessage);
        }

        void warn(std::string_view message) {
            LogMessage logMessage{
                LogLevel::WARN,
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

    void Logger::debug(std::string_view message) {
        impl_ ->debug(message);
    }

    void Logger::error(std::string_view message) {
        impl_ ->error(message);
    }

    void Logger::warn(std::string_view message) {
        impl_ ->warn(message);
    }
}