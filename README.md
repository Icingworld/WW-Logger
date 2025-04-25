# WW-Logger

该项目是`WW`系列中，作为学习用途的轻量化日志库

## 特点

+ 支持同步日志和异步日志
+ 支持线程安全
+ 支持多输出接口
+ 支持日志级别过滤
+ 自定义日志格式
+ 支持日志文件轮转

## 安装

### Cmake

+ 获取代码并移动项目文件夹到项目的合适位置

```cmake
add_subdirectory(WW-Logger)
```

+ 链接库

```cmake
target_link_libraries(${YOUR_EXECUTABLE_NAME} PRIVATE logger)
```

## 使用

简单示例如下所示，或浏览`test`文件夹源码

### 同步日志

同步日志支持终端输出、文件输出等所有输出方式，见[sync_logger_test.cpp](test/src/sync_logger_test.cpp)

```cpp
#include <Logger.h>
#include <Sinks/ConsoleSink.h>
#include <Sinks/DefaultFileSink.h>

int main()
{
    // 获取同步日志实例
    WW::Logger & logger = WW::Logger::getSyncLogger("SingleThreadSyncLogger");

    // 设置日志过滤级别
    logger.setLevel(WW::LogLevel::Info);

    // 创建终端输出
    auto console_sink = std::make_shared<WW::ConsoleSink>();
    logger.addSink(console_sink);

    // 创建文件输出
    std::string filename = "sync_log.txt";
    auto file_sink = std::make_shared<WW::DefaultFileSink>(filename);
    logger.addSink(file_sink);

    // 输出日志
    logger.trace("This is a trace message.");
    logger.debug("This is a debug message.");
    logger.info("This is an info message.");
    logger.warn("This is a warning message.");
    logger.error("This is an error message.");
    logger.fatal("This is a fatal message.");

    // 刷新日志
    logger.flush();
}
```

### 异步日志

异步日志只支持文件输出方式，见[async_logger_test.cpp](test/src/async_logger_test.cpp)

```cpp
#include <Logger.h>
#include <Sinks/DefaultFileSink.h>

int main()
{
    // 获取异步日志实例
    WW::Logger & logger = WW::Logger::getAsyncLogger("SingleThreadAsyncLogger");
    
    // 创建文件输出
    auto filename = "async_logger_test_single_thread_log.txt";
    auto file_sink = std::make_shared<WW::DefaultFileSink>(filename);
    logger.addSink(file_sink);

    // 输出日志
    logger.trace("This is a trace message.");
    logger.debug("This is a debug message.");
    logger.info("This is an info message.");
    logger.warn("This is a warning message.");
    logger.error("This is an error message.");
    logger.fatal("This is a fatal message.");

    // 刷新日志
    logger.flush();
}
```

### 文件轮转日志

轮转日志支持设置单个日志文件大小和轮转日志数量，见[rotate_logger_test.cpp](test/src/rotate_logger_test.cpp)

```cpp
#include <Logger.h>
#include <Sinks/RotateFileSink.h>

TEST(RotateLoggerTest, SingleThread)
{
    // 获取同步日志实例
    WW::Logger & logger = WW::Logger::getSyncLogger("SingleThreadRotateLogger");

    // 创建文件输出
    std::string filename = "rotate_logger_test_single_thread_log.txt";
    // 设置单个日志文件大小
    constexpr std::size_t max_size = 128 * 1024;
    // 设置轮转日志数量
    constexpr std::size_t max_files = 3;

    auto file_sink = std::make_shared<WW::RotateFileSink>(filename, max_size, max_files);
    logger.addSink(file_sink);

    // 输出日志
    for (int i = 0; i < 10000; ++i) {
        logger.info(std::string("This is an info message. - ") + std::to_string(i));
    }

    // 刷新日志
    logger.flush();
}
```

### 时间切片日志

时间切片日志支持设置切片时间，并提供了封装好的`HourlyFileSink`和`DailyFileSink`，见[timed_logger_test.cpp](test/src/timed_logger_test.cpp)

```cpp
#include <Logger.h>
#include <Sinks/TimedFileSink.h>

TEST(TimedLoggerTest, SingleThread)
{
    // 获取同步日志实例
    WW::Logger & logger = WW::Logger::getSyncLogger("SingleThreadTimedLogger");

    // 创建文件输出
    std::string filename = "timed_logger_test_single_thread_log.txt";
    // 设置切片时间为3秒
    auto duration = std::chrono::seconds(3);

    auto file_sink = std::make_shared<WW::TimedFileSink>(filename, duration);
    logger.addSink(file_sink);

    // 输出日志
    for (int i = 0; i < 3; ++i) {
        logger.info("This is an info message.");

        // 保证触发切片
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    // 刷新日志
    logger.flush();
}
```

### 格式化输出

支持自定义格式化输出，可以通过设置`pattern`来设置格式，也可以自定义并传入`Formatter`，见[formatter_logger_test.cpp](test/src/formatter_logger_test.cpp)

```cpp
#include <Logger.h>
#include <Sinks/ConsoleSink.h>
#include <Sinks/DefaultFileSink.h>

TEST(FormatterTest, Format)
{
    // 获取同步日志实例
    WW::Logger & logger = WW::Logger::getSyncLogger("FormatterLogger");
    // 设置全局日志格式
    logger.setFormatter("[%F %T][%L] %v");

    // 创建终端输出
    auto console_sink = std::make_shared<WW::ConsoleSink>();
    logger.addSink(console_sink);

    // 创建文件输出
    std::string filename = "formatter_test_log.txt";
    auto file_sink = std::make_shared<WW::DefaultFileSink>(filename);
    logger.addSink(file_sink);

    // 输出日志
    logger.trace("This is a trace message.");
    logger.debug("This is a debug message.");
    logger.info("This is an info message.");
    logger.warn("This is a warning message.");
    logger.error("This is an error message.");
    logger.fatal("This is a fatal message.");

    // 修改全局日志格式
    logger.setFormatter("[%F %T][%L][%V] %v");

    // 输出日志
    logger.trace("This is a trace message.", __FILE__, __LINE__, __FUNCTION__);
    logger.debug("This is a debug message.", __FILE__, __LINE__, __FUNCTION__);
    logger.info("This is an info message.", __FILE__, __LINE__, __FUNCTION__);
    logger.warn("This is a warning message.", __FILE__, __LINE__, __FUNCTION__);
    logger.error("This is an error message.", __FILE__, __LINE__, __FUNCTION__);
    logger.fatal("This is a fatal message.", __FILE__, __LINE__, __FUNCTION__);

    // 刷新日志
    logger.flush();
}
```

## 文档

项目文档参见[Wiki](https://github.com/Icingworld/WW-Logger/wiki)页面
