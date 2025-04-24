#pragma once

#include <Sinks/SinkBase.h>

namespace WW
{

/**
 * @brief 控制台日志输出
 */
class ConsoleSink : public SinkBase
{
public:
    explicit ConsoleSink(std::shared_ptr<FormatterBase> formatter = std::make_shared<DefaultFormatter>());

    ~ConsoleSink() override = default;

public:
    /**
     * @brief 输出日志到控制台
     */
    void log(const LogMessage & msg) override;

    void flush() override;
};

} // namespace WW
