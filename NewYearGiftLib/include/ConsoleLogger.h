#pragma once
#include "ILogger.h"
#include "Export.h"

class NEWYEAR_GIFT_API ConsoleLogger : public ILogger {
public:
    void log(const std::string& message) override;
    void logError(const std::string& message) override;
};