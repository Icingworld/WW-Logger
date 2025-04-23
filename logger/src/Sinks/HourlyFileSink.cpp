#include "HourlyFileSink.h"

namespace WW
{

HourlyFileSink::HourlyFileSink(const std::string & filename, std::shared_ptr<FormatterBase> formatter)
    : TimedFileSink(filename, std::chrono::hours(1),formatter)
{
}

void HourlyFileSink::log(const LogMessage & msg)
{
    TimedFileSink::log(msg);
}

void HourlyFileSink::flush()
{
    TimedFileSink::flush();
}

} // namespace WW
