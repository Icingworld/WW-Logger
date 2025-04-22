#include "MyFormatter.h"

#include <sstream>
#include <iomanip>

std::string MyFormatter::format(const WW::LogMessage & msg)
{
    std::ostringstream oss;

    time_t time = std::chrono::system_clock::to_time_t(msg.timestamp);
    std::tm tm_time;

#ifdef _WIN32
    localtime_s(&tm_time, &time);   // Windows
#else
    localtime_r(&time, &tm_time);   // Linux/Mac
#endif

    oss << "[" << std::put_time(&tm_time, "%Y-%m-%d %H:%M:%S") << "] ";

    oss << "[" << formatLogLevel(msg.level) << "] ";

    oss << msg.message;

    return oss.str();
}

std::string MyFormatter::formatLogLevel(WW::LogLevel level)
{
    switch (level) {
    case WW::LogLevel::Trace:
        return "TRACE";
    case WW::LogLevel::Debug:
        return "DEBUG";
    case WW::LogLevel::Info:
        return "INFO";
    case WW::LogLevel::Warn:
        return "WARN";
    case WW::LogLevel::Error:
        return "ERROR";
    case WW::LogLevel::Fatal:
        return "FATAL";
    case WW::LogLevel::Off:
        return "OFF";
    default:
        return "UNKNOWN";
    }
}