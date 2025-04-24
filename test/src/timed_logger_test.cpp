/**
 * @file timed_logger_test.cpp
 * @brief 按时间切片的日志测试
 */

#include <gtest/gtest.h>
#include <Logger.h>
#include <Sinks/TimedFileSink.h>

TEST(TimedLoggerTest, SingleThread)
{
    WW::Logger & logger = WW::Logger::getSyncLogger("SingleThreadTimedLogger");
    logger.setLevel(WW::LogLevel::Info);

    // 文件输出
    std::string filename = "timed_logger_test_single_thread_log.txt";
    auto duration = std::chrono::seconds(3);
    auto file_sink = std::make_shared<WW::TimedFileSink>(filename, duration);
    logger.addSink(file_sink);

    // 打印日志
    for (int i = 0; i < 3; ++i) {
        logger.info("This is an info message.");
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    // 刷新日志
    logger.flush();
}