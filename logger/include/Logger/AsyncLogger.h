#pragma once

#include <Logger/LoggerBase.h>

namespace WW
{

/**
 * @brief 异步日志
 */
class AsyncLogger : public LoggerBase
{
public:
    void log(LogLevel level, const std::string & message, const char * file = "", unsigned int line = 0, const char * function = "") override;

    void flush() override;

    LogType getType() const override;
};

} // namespace WW
