#pragma once

#include <Sinks/DefaultFileSink.h>

namespace WW
{

/**
 * @brief 按时间切片的日志文件输出
 */
class TimedFileSink : public DefaultFileSink
{
protected:
    std::chrono::system_clock::time_point last_time;    // 上次切片时间
    std::chrono::duration<int> duration;                // 切片间隔

public:
    explicit TimedFileSink(const std::string & filename, std::chrono::duration<int> duration = std::chrono::hours(24), std::shared_ptr<FormatterBase> formatter = std::make_shared<DefaultFormatter>());

    ~TimedFileSink() override = default;

public:
    /**
     * @brief 设置切片间隔
     */
    void setDuration(std::chrono::duration<int> duration);

    /**
     * @brief 设置切片间隔（小时）
     */
    void setDurationHours(unsigned int hours);

    /**
     * @brief 设置切片间隔（天）
     */
    void setDurationDays(unsigned int days);

    /**
     * @brief 设置切片间隔（周）
     */
    void setDurationWeeks(unsigned int weeks);

    void log(const LogMessage & msg) override;

    void flush() override;

private:
    /**
     * @brief 是否需要切片
     */
    bool shouldRotate(const std::chrono::system_clock::time_point & cur_time);

    /**
     * @brief 轮转日志文件
     */
    void rotate();

    /**
     * @brief 格式化时间为文件名
     */
    std::string formatTime() const;
};

} // namespace WW
