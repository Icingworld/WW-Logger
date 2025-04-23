#include "RotateFileSink.h"

namespace WW
{

RotateFileSink::RotateFileSink(const std::string & filename, std::size_t max_size, std::size_t max_files, std::shared_ptr<FormatterBase> formatter)
    : DefaultFileSink(filename, formatter)
    , max_size(max_size)
    , max_files(max_files)
{
}

RotateFileSink::~RotateFileSink()
{
}

void RotateFileSink::log(const LogMessage & msg)
{
    DefaultFileSink::log(msg);

    if (getCurrentFileSize() > max_size) {
        rotate();
    }
}

void RotateFileSink::flush()
{
    DefaultFileSink::flush();
}

std::size_t RotateFileSink::getCurrentFileSize() const
{
    std::ifstream cur_file(filename, std::ios::binary | std::ios::ate);
    if (!cur_file.is_open()) {
        throw std::runtime_error("Failed to open log file: " + filename);
        return 0;
    }
    return static_cast<std::size_t>(cur_file.tellg());
}

void RotateFileSink::rotate()
{
    if (file.is_open()) {
        file.close();
    }

    std::string oldest_file = filename + "." + std::to_string(max_files);
    if (std::ifstream(oldest_file).good()) {
        std::remove(oldest_file.c_str());
    }

    for (std::size_t i = max_files - 1; i > 0; --i) {
        std::string src = filename + "." + std::to_string(i);
        if (std::ifstream(src).good()) {
            std::string target = filename + "." + std::to_string(i + 1);
            std::rename(src.c_str(), target.c_str());
        }
    }

    if (std::ifstream(filename).good()) {
        std::rename(filename.c_str(), (filename + ".1").c_str());
    }

    file.open(filename, std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open log file: " + filename);
    }
}

} // namespace WW
