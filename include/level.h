//
// Created by elijah on 11/22/25.
//

#ifndef LOGSAR_LEVEL_H
#define LOGSAR_LEVEL_H
#include <string_view>

namespace logsar {
    /**
    * @brief Represents the severity level of a log message
    */
    enum class LogLevel {
        INFO,
        WARN,
        ERROR,
        DEBUG,
        TRACE,
    };

    constexpr std::string_view toString(LogLevel level) noexcept {
        switch (level) {
            case LogLevel::INFO:    return "INFO";
            case LogLevel::WARN: 	return "WARNING";
            case LogLevel::ERROR:   return "ERROR";
            case LogLevel::DEBUG:   return "DEBUG";
            case LogLevel::TRACE:   return "TRACE";
        }
        return "DEBUG";
    }
}

#endif //LOGSAR_LEVEL_H