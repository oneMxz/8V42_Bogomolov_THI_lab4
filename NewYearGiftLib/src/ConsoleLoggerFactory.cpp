#include "ConsoleLoggerFactory.h"

ILogger* ConsoleLoggerFactory::createLogger() {
    return new ConsoleLogger();
}