#include "FileSink.h"

namespace WW
{

FileSink::FileSink(const std::string & filename, std::shared_ptr<Formatter> formatter)
    : Sink(formatter)
    , filename(filename)
    , file(filename, std::ios::out | std::ios::app)
{
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open log file: " + filename);
    }
}

FileSink::~FileSink()
{
    if (file.is_open()) {
        file.close();
    }
}

void FileSink::log(const LogMessage & msg)
{
    if (msg.level == LogLevel::Off || !file.is_open()) {
        return;
    }

    file << formatter->format(msg) << std::endl;
}

void FileSink::flush()
{
    if (file.is_open()) {
        file.flush();
    }
}

} // namespace WW
