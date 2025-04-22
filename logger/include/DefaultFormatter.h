#pragma once

#include "Formatter.h"

namespace WW
{

/**
 * @brief 默认格式化器
 */
class DefaultFormatter : public Formatter
{
public:
    std::string format(const LogMessage & msg) override;

private:
    /**
     * @brief 格式化日志等级
     */
    std::string formatLogLevel(LogLevel level);
};

} // namespace WW
