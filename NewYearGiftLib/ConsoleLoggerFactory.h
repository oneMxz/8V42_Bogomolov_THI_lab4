#pragma once
#include "LoggerFactory.h"
#include "ConsoleLogger.h"

class ConsoleLoggerFactory : public LoggerFactory {
public:
    ILogger* createLogger() override;
};