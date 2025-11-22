//
// Created by elijah on 11/22/25.
//

#ifndef LOGSAR_MESSAGE_H
#define LOGSAR_MESSAGE_H

#include "level.h"
#include <chrono>
#include <string_view>

namespace logsar {
    struct LogMessage {
        LogLevel level;
        std::chrono::system_clock::time_point timestamp;
        std::string_view message;
    };
}

#endif //LOGSAR_MESSAGE_H