#pragma once

#include "SyncLogger.h"
#include "AsyncLogger.h"
#include "Formatter.h"

namespace WW
{

/**
 * @brief 日志
 */
class Logger
{
private:
    LogLevel level;                         // 日志等级
    std::shared_ptr<LoggerBase> logger;     // 日志实例

private:
    Logger();

    explicit Logger(LogLevel level);

    explicit Logger(LogType type);

    Logger(LogLevel level, LogType type);

    Logger(const Logger &) = delete;

    Logger & operator=(const Logger &) = delete;

    Logger(Logger &&) = delete;

    Logger & operator=(Logger &&) = delete;

public:
    ~Logger();

    /**
     * @brief 获取日志实例
     */
    static Logger & getLogger();

    /**
     * @brief 设置日志类型
     */
    void setType(LogType type);

    /**
     * @brief 设置日志等级
     */
    void setLevel(LogLevel level);

    /**
     * @brief 添加日志输出
     */
    void addSink(std::shared_ptr<Sink> sink);

    /**
     * @brief 输出日志
     */
    void log(LogLevel level, const std::string & message, const char * file = "", unsigned int line = 0, const char * function = "");

    /**
     * @brief 刷新日志输出
     */
    void flush();
};

} // namespace WW
