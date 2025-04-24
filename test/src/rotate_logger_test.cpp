/**
 * @file rotate_logger_test.cpp
 * @brief 单线程的轮转文件测试
 */

#include <gtest/gtest.h>
#include <Logger.h>
#include <Sinks/RotateFileSink.h>

TEST(RotateLoggerTest, SingleThread)
{
    WW::Logger & logger = WW::Logger::getSyncLogger("SingleThreadRotateLogger");
    logger.setLevel(WW::LogLevel::Info);

    // 文件输出
    std::string filename = "rotate_logger_test_single_thread_log.txt";
    constexpr std::size_t max_size = 128 * 1024;
    constexpr std::size_t max_files = 3;
    auto file_sink = std::make_shared<WW::RotateFileSink>(filename, max_size, max_files);
    logger.addSink(file_sink);

    for (int i = 0; i < 10000; ++i) {
        logger.info(std::string("This is an info message. - ") + std::to_string(i));
    }

    logger.flush();
}