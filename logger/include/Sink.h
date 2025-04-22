#pragma once

#include <memory>

#include "DefaultFormatter.h"
#include "LogMessage.h"

namespace WW
{

/**
 * @brief 日志输出接口
 */
class Sink
{
protected:
    std::shared_ptr<Formatter> formatter;   // 日志格式化器

public:
    explicit Sink(std::shared_ptr<Formatter> formatter = std::make_shared<DefaultFormatter>());

    virtual ~Sink() = default;

public:
    /**
     * @brief 输出日志
     */
    virtual void log(const LogMessage & msg) = 0;

    /**
     * @brief 刷新
     */
    virtual void flush() = 0;

    void setFormatter(std::shared_ptr<Formatter> formatter);
};

} // namespace WW
