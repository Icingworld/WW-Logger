#include "AsyncLogger.h"

namespace WW
{

void AsyncLogger::log(LogLevel level, const std::string & message, const char * file, unsigned int line, const char * function)
{
    // TODO
}

void AsyncLogger::flush()
{
    // TODO
}

LogType AsyncLogger::getType() const
{
    return LogType::Async;
}

} // namespace WW