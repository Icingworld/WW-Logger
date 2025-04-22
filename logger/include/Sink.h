#pragma once

#include "LogMessage.h"

namespace WW
{

/**
 * @brief 日志输出接口基类
 */
class Sink
{
public:
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
};

} // namespace WW
