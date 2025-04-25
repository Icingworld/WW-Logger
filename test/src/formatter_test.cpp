/**
 * @file formatter_test.cpp
 * @brief 格式化测试
 */

#include <gtest/gtest.h>
#include <Logger.h>
#include <Sinks/ConsoleSink.h>
#include <Sinks/DefaultFileSink.h>

TEST(FormatterTest, Format)
{
    WW::Logger & logger = WW::Logger::getSyncLogger("FormatterLogger");
    logger.setLevel(WW::LogLevel::Debug);
    logger.setFormatter("[%F %T][%L] %v");

    // 终端输出
    auto console_sink = std::make_shared<WW::ConsoleSink>();
    logger.addSink(console_sink);

    // 文件输出
    std::string filename = "formatter_test_log.txt";
    auto file_sink = std::make_shared<WW::DefaultFileSink>(filename);
    logger.addSink(file_sink);

    // 打印日志
    logger.trace("This is a trace message.");
    logger.debug("This is a debug message.");
    logger.info("This is an info message.");
    logger.warn("This is a warning message.");
    logger.error("This is an error message.");
    logger.fatal("This is a fatal message.");

    // 修改格式
    logger.setFormatter("[%F %T][%L][%V] %v");

    // 打印日志
    logger.trace("This is a trace message.", __FILE__, __LINE__, __FUNCTION__);
    logger.debug("This is a debug message.", __FILE__, __LINE__, __FUNCTION__);
    logger.info("This is an info message.", __FILE__, __LINE__, __FUNCTION__);
    logger.warn("This is a warning message.", __FILE__, __LINE__, __FUNCTION__);
    logger.error("This is an error message.", __FILE__, __LINE__, __FUNCTION__);
    logger.fatal("This is a fatal message.", __FILE__, __LINE__, __FUNCTION__);

    // 刷新日志
    logger.flush();
}
