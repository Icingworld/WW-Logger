#include "TimedFileSink.h"

#include <sstream>
#include <iomanip>

namespace WW
{

TimedFileSink::TimedFileSink(const std::string & filename, std::chrono::duration<int> duration, std::shared_ptr<FormatterBase> formatter)
    : DefaultFileSink(filename, formatter)
    , last_time()
    , duration(duration)
{
}

void TimedFileSink::setDuration(std::chrono::duration<int> duration)
{
    this->duration = duration;
}

void TimedFileSink::setDurationHours(unsigned int hours)
{
    this->duration = std::chrono::hours(hours);
}

void TimedFileSink::setDurationDays(unsigned int days)
{
    this->duration = std::chrono::hours(days * 24);
}

void TimedFileSink::setDurationWeeks(unsigned int weeks)
{
    this->duration = std::chrono::hours(weeks * 24 * 7);
}

void TimedFileSink::log(const LogMessage & msg)
{
    auto cur_time = std::chrono::system_clock::now();
    if (shouldRotate(cur_time)) {
        rotate();
    }

    DefaultFileSink::log(msg);
}

void TimedFileSink::flush()
{
    DefaultFileSink::flush();
}

bool TimedFileSink::shouldRotate(const std::chrono::system_clock::time_point & cur_time)
{
    if (cur_time - last_time > duration) {
        last_time = cur_time;
        return true;
    }
    return false;
}

void TimedFileSink::rotate()
{
    if (file.is_open()) {
        file.close();
    }

    std::string new_file = name + "_" + formatTime() + suffix;
    file.open(new_file, std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open log file: " + new_file);
    }
}

std::string TimedFileSink::formatTime() const
{
    std::time_t time = std::chrono::system_clock::to_time_t(last_time);
    std::tm tm = *std::localtime(&time);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d_%H-%M-%S");

    return oss.str();
}

} // namespace WW
