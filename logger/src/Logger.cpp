#include "Logger.h"

namespace WW
{

Logger::Logger()
    : Logger(LogLevel::Info, LogType::Sync)
{
}

Logger::Logger(LogLevel level)
    : Logger(level, LogType::Sync)
{
}

Logger::Logger(LogType type)
    : Logger(LogLevel::Info, type)
{
}

Logger::Logger(LogLevel level, LogType type)
    : level(level)
{
    if (type == LogType::Sync) {
        logger = std::make_shared<SyncLogger>();
    } else if (type == LogType::Async) {
        logger = std::make_shared<AsyncLogger>();
    }
}

Logger::~Logger()
{
    flush();
}

Logger & Logger::getLogger()
{
    static Logger instance;
    return instance;
}

void Logger::setType(LogType type)
{
    if ((type == LogType::Sync && logger->getType() == LogType::Sync) ||
        (type == LogType::Async && logger->getType() == LogType::Async)) {
        return;
    }

    if (type == LogType::Sync) {
        logger = std::make_shared<SyncLogger>();
    } else if (type == LogType::Async) {
        logger = std::make_shared<AsyncLogger>();
    }
}

void Logger::setLevel(LogLevel level)
{
    this->level = level;
}

void Logger::addSink(std::shared_ptr<Sink> sink)
{
    logger->addSink(sink);
}

void Logger::log(LogLevel level, const std::string & message, const char * file, unsigned int line, const char * function)
{
    if (level < this->level)
        return;
    
    logger->log(level, message, file, line, function);
}

void Logger::flush()
{
    logger->flush();
}

} // namespace WW
