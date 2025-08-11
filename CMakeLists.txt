cmake_minimum_required(VERSION 3.31)
project(logsar VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)

# -------------------------------------------------------------
# Define the C++ Library
# -------------------------------------------------------------

add_library(logsar SHARED
        src/logger.cpp
)

target_include_directories(logsar
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# -------------------------------------------------------------
# Define the C API Wrapper Library
# -------------------------------------------------------------

add_library(logsarc SHARED
        src/logger_capi.cpp
)

target_link_libraries(logsarc PUBLIC logsar)

target_include_directories(logsarc
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/c_api>
        $<INSTALL_INTERFACE:include/c_api>
)

# -------------------------------------------------------------
# Library Properties and Installation
# -------------------------------------------------------------

set_target_properties(logsarc PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
)

# Install the headers and libraries
install(TARGETS logsar logsarc
        EXPORT logsarTargets  # Use a clear name for the export set
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)

# This command creates the `logsarTargets.cmake` file and installs it.
install(EXPORT logsarTargets
        FILE logsarTargets.cmake
        NAMESPACE logsar::  # Prefix all imported targets with this namespace
        DESTINATION share/logsar/cmake
)

# Install header files
install(DIRECTORY include/logger
        DESTINATION include
)

install(DIRECTORY include/c_api
        DESTINATION include
)

# -------------------------------------------------------------
# Example Executable
# -------------------------------------------------------------

add_executable(example examples/basic_usage.cpp)
target_link_libraries(example logsarc)