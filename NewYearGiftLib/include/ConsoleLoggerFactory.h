#pragma once
#include "LoggerFactory.h"
#include "ConsoleLogger.h"
#include "Export.h"

class NEWYEAR_GIFT_API ConsoleLoggerFactory : public LoggerFactory {
public:
    ILogger* createLogger() override;
};