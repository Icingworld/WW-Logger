#pragma once

#include "LogMessage.h"

namespace WW
{

/**
 * @brief 日志格式化器
 */
class Formatter
{
public:
    virtual ~Formatter() = default;

public:
    virtual std::string format(const LogMessage & msg) = 0;
};

} // namespace WW
