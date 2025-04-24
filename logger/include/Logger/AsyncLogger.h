#pragma once

#include <Logger/LoggerBase.h>
#include <Logger/AsyncWorker.h>
#include <Formatter/DefaultFormatter.h>

namespace WW
{

/**
 * @brief 异步日志
 */
class AsyncLogger : public LoggerBase
{
private:
    std::shared_ptr<FormatterBase> formatter;   // 日志格式化器
    AsyncWorker worker;                         // 异步日志管理线程
    std::mutex mutex;                           // 互斥锁

public:
    AsyncLogger();

    ~AsyncLogger() override;

public:
    void log(LogLevel level, const std::string & message, const char * file = "", unsigned int line = 0, const char * function = "") override;

    void flush() override;

    LogType getType() const override;

    /**
     * @brief 设置日志格式化器
     */
    void setFormatter(std::shared_ptr<FormatterBase> formatter);

private:
    /**
     * @brief 回调函数
     */
    void callback(const char * data, std::size_t size);
};

} // namespace WW
