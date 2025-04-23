#pragma once

#include <Formatter/FormatterBase.h>

namespace WW
{

/**
 * @brief 默认格式化器
 */
class DefaultFormatter : public FormatterBase
{
public:
    std::string format(const LogMessage & msg) override;

private:
    /**
     * @brief 格式化日志等级
     */
    std::string formatLogLevel(LogLevel level) const;
};

} // namespace WW
