#include <SFML/Graphics.hpp>
#include <spdlog/sinks/basic_file_sink.h>
#include <iostream>

std::shared_ptr<spdlog::logger> initializeLogger() {
    try {
        auto FILE_LOG = spdlog::basic_logger_mt("file-log", "../logs/logs.txt");
        return FILE_LOG;

    } catch (const spdlog::spdlog_ex &error) {
        std::cerr << "Log init failed: " << error.what() << std::endl;
        return nullptr;
    }
}

auto FILE_LOG = initializeLogger();

int main([[maybe_unused]] int argc, [[maybe_unused]] char ** argv) {

    FILE_LOG -> info("Main Function is Initialized");
    return 0;
}