#include <MyFormatter.h>
#include <Logger.h>
#include <Sinks/ConsoleSink.h>
#include <Sinks/DefaultFileSink.h>

int main()
{
    // 获取实例
    WW::Logger & logger = WW::Logger::getDefaultLogger("MyLogger");

    // 设置日志类型
    logger.setType(WW::LogType::Async);

    // 设置终端输出
    WW::ConsoleSink sink;
    // 设置格式化器
    sink.setFormatter(std::make_shared<MyFormatter>());
    // 添加输出接口
    logger.addSink(std::make_shared<WW::ConsoleSink>());

    // 设置文件输出
    std::string filename = "log.txt";
    WW::DefaultFileSink file_sink(filename);
    // 设置格式化器
    file_sink.setFormatter(std::make_shared<MyFormatter>());
    // 添加输出接口
    logger.addSink(std::make_shared<WW::DefaultFileSink>(filename));

    // 设置日志级别
    logger.setLevel(WW::LogLevel::Debug);

    // 打印日志
    logger.log(WW::LogLevel::Debug, "A debug message.");
    logger.log(WW::LogLevel::Info, "Hello, World!");
    logger.debug("A debug message.", __FILE__, __LINE__, __FUNCTION__);
}