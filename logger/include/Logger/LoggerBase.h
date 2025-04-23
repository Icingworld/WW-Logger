#pragma once

#include <string>
#include <vector>

#include <Sinks/SinkBase.h>
#include <LogLevel.h>

namespace WW
{

/**
 * @brief 日志类型
 */
enum class LogType
{
    Sync,       // 同步
    Async       // 异步
};

/**
 * @brief 日志类接口
 */
class LoggerBase
{
protected:
    std::vector<std::shared_ptr<SinkBase>> sinks;   // 输出接口列表

public:
    LoggerBase() = default;

    virtual ~LoggerBase() = default;

public:
    virtual void log(LogLevel level, const std::string & message, const char * file = "", unsigned int line = 0, const char * function = "") = 0;

    virtual void flush() = 0;

    virtual LogType getType() const = 0;

    /**
     * @brief 添加输出接口
     */
    void addSink(std::shared_ptr<SinkBase> sink);
};

} // namespace WW
