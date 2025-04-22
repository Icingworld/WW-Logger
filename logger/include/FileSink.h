#pragma once

#include <fstream>

#include "Sink.h"

namespace WW
{

/**
 * @brief 文件日志输出
 */
class FileSink : public Sink
{
private:
    std::string filename;                   // 日志文件名
    std::ofstream file;                     // 日志文件

public:
    explicit FileSink(const std::string & filename, std::shared_ptr<Formatter> formatter = std::make_shared<DefaultFormatter>());

    ~FileSink() override;

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
