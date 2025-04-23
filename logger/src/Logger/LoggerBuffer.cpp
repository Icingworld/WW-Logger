#include "LoggerBuffer.h"

namespace WW
{

LoggerBuffer::LoggerBuffer()
    : LoggerBuffer(1024 * 1024)
{
}

LoggerBuffer::LoggerBuffer(std::size_t size)
    : buffer(size)
    , write_pos(0)
    , read_pos(0)
{
}

bool LoggerBuffer::push_back(const char * data, std::size_t size)
{
    if (write_pos + size > buffer.size()) {
        return false;
    }

    std::memcpy(buffer.data() + write_pos, data, size);
    write_pos += size;
    return true;
}

void LoggerBuffer::read(char *& data, std::size_t & size)
{
    data = buffer.data() + read_pos;
    size = write_pos - read_pos;
    read_pos = write_pos;
}

void LoggerBuffer::swap(LoggerBuffer & other)
{
    buffer.swap(other.buffer);
    std::swap(write_pos, other.write_pos);
    std::swap(read_pos, other.read_pos);
}

void LoggerBuffer::reset()
{
    write_pos = 0;
    read_pos = 0;
}

} // namespace WW
