/**
 * @file async_logger_test.cpp
 * @brief 异步日志的单线程、多线程功能测试
 */

#include <gtest/gtest.h>
#include <Logger.h>
#include <Sinks/DefaultFileSink.h>

TEST(AsyncLoggerTest, SingleThreadAsyncLogger)
{
    WW::Logger & logger = WW::Logger::getAsyncLogger("SingleThreadAsyncLogger");
    
    // 文件输出
    auto filename = "async_logger_test_single_thread_log.txt";
    auto file_sink = std::make_shared<WW::DefaultFileSink>(filename);
    logger.addSink(file_sink);

    // 打印日志
    logger.trace("This is a trace message.");
    logger.debug("This is a debug message.");
    logger.info("This is an info message.");
    logger.warn("This is a warning message.");
    logger.error("This is an error message.");
    logger.fatal("This is a fatal message.");

    // 刷新日志
    logger.flush();
}

TEST(AsyncLoggerTest, MultiThreadAsyncLogger)
{
    WW::Logger & logger = WW::Logger::getAsyncLogger("MultiThreadAsyncLogger");

    // 文件输出
    auto filename = "async_logger_test_multi_thread_log.txt";
    auto file_sink = std::make_shared<WW::DefaultFileSink>(filename);
    logger.addSink(file_sink);

    // 创建线程
    constexpr int threads_num = 8;
    constexpr int logs_per_thread = 2000;

    std::vector<std::thread> threads;
    for (int i = 0; i < threads_num; i++) {
        threads.emplace_back([&logger, i, logs_per_thread] {
            for (int j = 0; j < logs_per_thread; j++) {
                logger.info("This is an info message.");
            }
        });
    }

    for (auto & thread : threads) {
        thread.join();
    }

    // 刷新日志
    logger.flush();
}