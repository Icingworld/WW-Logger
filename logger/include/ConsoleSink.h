#pragma once

#include "Sink.h"

namespace WW
{

/**
 * @brief 控制台日志输出
 */
class ConsoleSink : public Sink
{
public:
    explicit ConsoleSink(std::shared_ptr<Formatter> formatter = std::make_shared<DefaultFormatter>());

public:
    /**
     * @brief 输出日志到控制台
     */
    void log(const LogMessage & msg) override;

    /**
     * @brief 强制刷新输出流
     */
    void flush() override;
};

} // namespace WW
