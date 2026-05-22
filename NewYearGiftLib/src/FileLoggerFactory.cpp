#include "FileLoggerFactory.h"

FileLoggerFactory::FileLoggerFactory(const std::string& filename) : _filename(filename) {}

ILogger* FileLoggerFactory::createLogger() {
    return new FileLogger(_filename);
}