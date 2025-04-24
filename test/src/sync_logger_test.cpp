/**
 * @file sync_logger_test.cpp
 * @brief 同步日志的单线程、多线程功能测试
 */

#include <gtest/gtest.h>
#include <Logger.h>
#include <Sinks/ConsoleSink.h>
#include <Sinks/DefaultFileSink.h>

class SyncLoggerTest : public testing::Test
{
public:
    SyncLoggerTest()
    {
    }
    
    ~SyncLoggerTest()
    {
    }

public:
    void SetUp()
    {
    }

    void TearDown()
    {
    }
};

TEST_F(SyncLoggerTest, SingleThreadSyncLogger)
{
    WW::Logger & logger = WW::Logger::getSyncLogger("SingleThreadSyncLogger");
    logger.setLevel(WW::LogLevel::Info);

    // 终端输出
    auto console_sink = std::make_shared<WW::ConsoleSink>();
    logger.addSink(console_sink);

    // 文件输出
    std::string filename = "sync_logger_test_single_thread_log.txt";
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

    // 验证日志文件
    std::ifstream in(filename);
    ASSERT_TRUE(in.good());

    std::stringstream buffer;
    buffer << in.rdbuf();
    std::string content = buffer.str();

    EXPECT_EQ(content.find("trace"), std::string::npos);
    EXPECT_EQ(content.find("debug"), std::string::npos);
    EXPECT_NE(content.find("info"), std::string::npos);
    EXPECT_NE(content.find("warning"), std::string::npos);
    EXPECT_NE(content.find("error"), std::string::npos);
    EXPECT_NE(content.find("fatal"), std::string::npos);
}

TEST_F(SyncLoggerTest, MultiThreadSyncLogger)
{
    WW::Logger & logger = WW::Logger::getSyncLogger("MultiThreadSyncLogger");
    logger.setLevel(WW::LogLevel::Info);

    // 终端输出
    auto console_sink = std::make_shared<WW::ConsoleSink>();
    logger.addSink(console_sink);

    // 文件输出
    std::string filename = "sync_logger_test_multi_thread_log.txt";
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