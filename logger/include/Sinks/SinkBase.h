#pragma once

#include <memory>

#include <Formatter/DefaultFormatter.h>
#include <LogMessage.h>

namespace WW
{

/**
 * @brief 日志输出接口
 */
class SinkBase
{
protected:
    std::shared_ptr<FormatterBase> formatter;   // 日志格式化器

public:
    explicit SinkBase(std::shared_ptr<FormatterBase> formatter = std::make_shared<DefaultFormatter>());

    virtual ~SinkBase() = default;

public:
    /**
     * @brief 输出日志
     */
    virtual void log(const LogMessage & msg) = 0;

    /**
     * @brief 刷新
     */
    virtual void flush() = 0;

    void setFormatter(std::shared_ptr<FormatterBase> formatter);
};

} // namespace WW
