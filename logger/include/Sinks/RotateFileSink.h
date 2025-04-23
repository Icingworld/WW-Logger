#pragma once

#include <Sinks/DefaultFileSink.h>

namespace WW
{

/**
 * @brief 按文件大小轮转的日志文件输出
 */
class RotateFileSink : public DefaultFileSink
{
private:
    std::size_t max_size;       // 最大文件大小
    std::size_t max_files;      // 最多文件数量

public:
    explicit RotateFileSink(const std::string & filename, std::size_t max_size = 1024 * 1024, std::size_t max_files = 1, std::shared_ptr<FormatterBase> formatter = std::make_shared<DefaultFormatter>());

    ~RotateFileSink() override = default;

public:
    void log(const LogMessage & msg) override;

    void flush() override;

private:
    /**
     * @brief 获取当前日志文件大小
     */
    std::size_t getCurrentFileSize() const;

    /**
     * @brief 轮转日志文件
     */
    void rotate();
};

} // namespace WW
