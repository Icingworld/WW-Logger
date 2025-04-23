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

    splitFilename();
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

void DefaultFileSink::log(const char * data, std::size_t size)
{
    if (file.is_open()) {
        file.write(data, size);
    }
}

void DefaultFileSink::flush()
{
    if (file.is_open()) {
        file.flush();
    }
}

void DefaultFileSink::splitFilename()
{
    std::size_t dot_pos = filename.find_last_of('.');
    if (dot_pos == std::string::npos) {
        name = filename;
        suffix = "";
    } else {
        name = filename.substr(0, dot_pos);
        suffix = filename.substr(dot_pos);
    }
}

} // namespace WW
