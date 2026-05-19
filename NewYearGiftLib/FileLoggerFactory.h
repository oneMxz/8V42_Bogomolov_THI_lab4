#pragma once
#include "LoggerFactory.h"
#include "FileLogger.h"
#include <string>

class FileLoggerFactory : public LoggerFactory {
private:
    std::string _filename;
public:
    FileLoggerFactory(const std::string& filename);
    ILogger* createLogger() override;
};