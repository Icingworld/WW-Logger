#include "MyFormatter.h"
#include "Logger.h"
#include "ConsoleSink.h"
#include "FileSink.h"

int main()
{
    // 获取实例
    WW::Logger & logger = WW::Logger::getLogger();

    // 设置终端输出
    WW::ConsoleSink sink;
    // 设置格式化器
    sink.setFormatter(std::make_shared<MyFormatter>());
    // 添加输出接口
    logger.addSink(std::make_shared<WW::ConsoleSink>());

    // 设置文件输出
    std::string filename = "log.txt";
    WW::FileSink file_sink(filename);
    // 设置格式化器
    file_sink.setFormatter(std::make_shared<MyFormatter>());
    // 添加输出接口
    logger.addSink(std::make_shared<WW::FileSink>(filename));

    // 设置日志级别
    logger.setLevel(WW::LogLevel::Info);

    // 打印日志
    logger.log(WW::LogLevel::Debug, "A debug message.");
    logger.log(WW::LogLevel::Info, "Hello, World!");
}