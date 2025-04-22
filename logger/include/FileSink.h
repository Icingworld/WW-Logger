#pragma once

#include "Sink.h"

namespace WW
{

/**
 * @brief 文件日志输出
 */
class FileSink : public Sink
{
private:
    std::string filename;   // 日志文件名

public:
    explicit FileSink(const std::string & filename);

    ~FileSink() override;

public:
    void log(const LogMessage & msg) override;

    void flush() override;
};

} // namespace WW
