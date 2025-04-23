#include "DailyFileSink.h"

namespace WW
{

DailyFileSink::DailyFileSink(const std::string & filename, std::shared_ptr<FormatterBase> formatter)
    : TimedFileSink(filename, std::chrono::hours(24), formatter)
{
}

void DailyFileSink::log(const LogMessage & msg)
{
    TimedFileSink::log(msg);
}

void DailyFileSink::flush()
{
    TimedFileSink::flush();
}

} // namespace WW
