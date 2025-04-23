#pragma once

#include <fstream>

#include <Sinks/SinkBase.h>

namespace WW
{

/**
 * @brief 默认文件日志输出
 */
class DefaultFileSink : public SinkBase
{
protected:
    std::string filename;                   // 日志文件名
    std::ofstream file;                     // 日志文件

public:
    explicit DefaultFileSink(const std::string & filename, std::shared_ptr<FormatterBase> formatter = std::make_shared<DefaultFormatter>());

    ~DefaultFileSink() override;

public:
    /**
     * @brief 输出日志到文件
     */
    void log(const LogMessage & msg) override;

    /**
     * @brief 强制刷新输出流
     */
    void flush() override;
};

} // namespace WW
