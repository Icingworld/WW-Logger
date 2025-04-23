#pragma once

#include <mutex>

#include <Logger/LoggerBase.h>

namespace WW
{

/**
 * @brief 同步日志
 */
class SyncLogger : public LoggerBase
{
private:
    std::mutex mutex;   // 互斥锁

public:
    SyncLogger() = default;

    ~SyncLogger() override = default;

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
