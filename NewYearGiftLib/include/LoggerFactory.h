#pragma once
#include "ILogger.h"
#include "Export.h"

class NEWYEAR_GIFT_API LoggerFactory {
public:
    virtual ILogger* createLogger() = 0;
    virtual ~LoggerFactory() = default;
};