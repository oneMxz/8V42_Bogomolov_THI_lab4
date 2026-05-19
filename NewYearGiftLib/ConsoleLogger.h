#pragma once
#include "ILogger.h"

class ConsoleLogger : public ILogger {
public:
    void log(const std::string& message) override;
    void logError(const std::string& message) override;
};