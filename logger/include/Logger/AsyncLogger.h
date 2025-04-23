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
    AsyncLogger() = default;

    ~AsyncLogger() override = default;

public:
    /**
     * @brief 输出日志
     */
    void log(LogLevel level, const std::string & message, const char * file = "", unsigned int line = 0, const char * function = "") override;

    /**
     * @brief 刷新日志输出
     */
    void flush() override;

    /**
     * @brief 获取日志类型
     */
    LogType getType() const override;
};

} // namespace WW
