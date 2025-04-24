#include "DefaultFormatter.h"

#include <sstream>
#include <iomanip>

namespace WW
{

std::string DefaultFormatter::format(const LogMessage & msg)
{
    std::ostringstream oss;

    oss << "[" << msg.name << "] ";

    time_t time = std::chrono::system_clock::to_time_t(msg.timestamp);
    std::tm tm_time;

#ifdef _WIN32
    localtime_s(&tm_time, &time);   // Windows
#else
    localtime_r(&time, &tm_time);   // Linux/Mac
#endif

    oss << "[" << std::put_time(&tm_time, "%Y-%m-%d %H:%M:%S") << "] ";

    if (msg.thread_id != std::thread::id()) {
        oss << "[TID:" << msg.thread_id << "] ";
    }

    oss << "[" << formatLogLevel(msg.level) << "] ";

    if (!msg.file.empty()) {
        oss << "[" << msg.file << ":" << msg.line << "] ";
    }

    if (!msg.function.empty()) {
        oss << "[" << msg.function << "] ";
    }

    oss << msg.message;

    return oss.str();
}

std::string DefaultFormatter::formatLogLevel(LogLevel level) const
{
    switch (level) {
    case LogLevel::Trace:
        return "TRACE";
    case LogLevel::Debug:
        return "DEBUG";
    case LogLevel::Info:
        return "INFO";
    case LogLevel::Warn:
        return "WARN";
    case LogLevel::Error:
        return "ERROR";
    case LogLevel::Fatal:
        return "FATAL";
    case LogLevel::Off:
        return "OFF";
    default:
        return "UNKNOWN";
    }
}

} // namespace WW
