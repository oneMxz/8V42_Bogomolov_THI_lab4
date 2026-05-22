#pragma once
#include <string>
#include "Export.h"

class NEWYEAR_GIFT_API ILogger {
public:
    virtual void log(const std::string& message) = 0;
    virtual void logError(const std::string& message) = 0;
    virtual ~ILogger() = default;
};