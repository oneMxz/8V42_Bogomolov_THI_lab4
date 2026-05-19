#pragma once
#include "ILogger.h"

class LoggerFactory {
public:
    virtual ILogger* createLogger() = 0;
    virtual ~LoggerFactory() = default;
};