#include "libraries.hpp"

#ifndef LOGGER_HPP
#define LOGGER_HPP

// A function to set up the logger and direct the output into /logs/logs.txt
std::shared_ptr<spdlog::logger> initialize_logger() {
    try {
        auto FILE_LOG = spdlog::basic_logger_mt("file-log", "../logs/logs.txt");
        return FILE_LOG;

    // Error Handling
    } catch (const spdlog::spdlog_ex &error) {
        std::cerr << "Log init failed: " << error.what() << std::endl;
        return nullptr;
    }
}

namespace logger {
    auto LOG_INTO = initialize_logger();
}

#endif