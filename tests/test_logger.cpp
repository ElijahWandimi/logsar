//
// Created by Elijah Wandimi on 11/08/2025.
//

#include "logger.h"
#include <iostream>

int main() {
    logsar::Logger logger;
    logger.info("Nice tyry, now the work begins!");

    std::cout << "[TEST] If you see the log above, it works.\n";
    return 0;
}
