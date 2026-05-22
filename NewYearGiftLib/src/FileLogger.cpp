#include "FileLogger.h"
#include <iostream>

FileLogger::FileLogger(const std::string& filename) {
    _file.open(filename, std::ios::app);
    if (!_file.is_open()) {
        std::cerr << "Не удалось открыть файл лога: " << filename << std::endl;
    }
}

FileLogger::~FileLogger() {
    if (_file.is_open()) _file.close();
}

void FileLogger::log(const std::string& message) {
    if (_file.is_open()) {
        _file << "[INFO] " << message << std::endl;
    }
}

void FileLogger::logError(const std::string& message) {
    if (_file.is_open()) {
        _file << "[ERROR] " << message << std::endl;
    }
}