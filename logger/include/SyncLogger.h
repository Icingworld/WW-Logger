#pragma once

#include <mutex>

#include "LoggerBase.h"

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
    /**
     * @brief 输出日志
     */
    void log(LogLevel level, const std::string & message, const char * file = "", unsigned int line = 0, const char * function = "") override;

    /**
     * @brief 刷新日志输出
     */
    void flush() override;

    LogType getType() const override;
};

} // namespace WW
