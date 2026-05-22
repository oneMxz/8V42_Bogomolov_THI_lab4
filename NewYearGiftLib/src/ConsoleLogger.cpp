#include "ConsoleLogger.h"
#include <iostream>

void ConsoleLogger::log(const std::string& message) {
    std::cout << "[INFO] " << message << std::endl;
}

void ConsoleLogger::logError(const std::string& message) {
    std::cerr << "[ERROR] " << message << std::endl;
}