#pragma once

#include <Sinks/TimedFileSink.h>

namespace WW
{

/**
 * @brief 按小时切片的日志输出
 */
class HourlyFileSink : public TimedFileSink
{
public:
    explicit HourlyFileSink(const std::string & filename, std::shared_ptr<FormatterBase> formatter = std::make_shared<DefaultFormatter>());

    ~HourlyFileSink() override = default;

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
