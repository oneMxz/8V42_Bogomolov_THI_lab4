#pragma once
#include "LoggerFactory.h"
#include "Export.h"
#include "FileLogger.h"
#include <string>

class NEWYEAR_GIFT_API FileLoggerFactory : public LoggerFactory {
private:
    std::string _filename;
public:
    FileLoggerFactory(const std::string& filename);
    ILogger* createLogger() override;
};