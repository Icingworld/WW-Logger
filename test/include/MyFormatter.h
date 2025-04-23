#pragma once

#include <Formatter/FormatterBase.h>

/**
 * @brief 自定义格式化器
 */
class MyFormatter : public WW::FormatterBase
{
public:
    /**
     * @brief 自定义不含线程ID、文件名、函数名的格式化器
     */
    std::string format(const WW::LogMessage & msg) override;

private:
    /**
     * @brief 格式化日志等级
     */
    std::string formatLogLevel(WW::LogLevel level);
};
