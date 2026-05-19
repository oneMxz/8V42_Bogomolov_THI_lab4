#pragma once
#include "ILogger.h"
#include <fstream>
#include <string>

class FileLogger : public ILogger {
private:
    std::ofstream _file;
public:
    FileLogger(const std::string& filename);
    ~FileLogger();
    void log(const std::string& message) override;
    void logError(const std::string& message) override;
};