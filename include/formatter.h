//
// Created by elijah on 11/23/25.
//

#ifndef LOGSAR_FORMATTER_H
#define LOGSAR_FORMATTER_H
#include "message.h"

namespace logsar {
    class Formatter {
    public:
        explicit Formatter(std::string_view format);
        virtual size_t format(LogMessage& msg, char* out, size_t size) noexcept = 0;
        private:
        std::string_view format_;
        ~Formatter() = default;
    };
}


#endif //LOGSAR_FORMATTER_H