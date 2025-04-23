#pragma once

#include <vector>

namespace WW
{

/**
 * @brief 异步日志缓冲区
 */
class LoggerBuffer
{
private:
    std::vector<char> buffer;       // 日志缓冲区
    std::size_t write_pos;          // 生产者位置
    std::size_t read_pos;           // 消费者位置

public:
    LoggerBuffer();

    explicit LoggerBuffer(std::size_t size);

    ~LoggerBuffer() = default;

public:
    /**
     * @brief 写日志到缓冲区
     */
    bool push_back(const char * data, std::size_t size);

    /**
     * @brief 从缓冲区读取日志
     */
    void read(char *& data, std::size_t & size);

    /**
     * @brief 交换日志缓冲区
     */
    void swap(LoggerBuffer & other);

    /**
     * @brief 重置日志缓冲区
     */
    void reset();
};

} // namespace WW
