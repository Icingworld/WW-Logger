#include "DefaultFileSink.h"

namespace WW
{

DefaultFileSink::DefaultFileSink(const std::string & filename, std::shared_ptr<FormatterBase> formatter)
    : SinkBase(formatter)
    , filename(filename)
    , file(filename, std::ios::out | std::ios::app)
{
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open log file: " + filename);
    }
}

DefaultFileSink::~DefaultFileSink()
{
    if (file.is_open()) {
        file.close();
    }
}

void DefaultFileSink::log(const LogMessage & msg)
{
    if (msg.level == LogLevel::Off || !file.is_open()) {
        return;
    }

    file << formatter->format(msg) << std::endl;
}

void DefaultFileSink::flush()
{
    if (file.is_open()) {
        file.flush();
    }
}

} // namespace WW
