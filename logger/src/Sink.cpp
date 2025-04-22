#include "Sink.h"

namespace WW
{

Sink::Sink(std::shared_ptr<Formatter> formatter)
    : formatter(std::move(formatter))
{
}

void Sink::setFormatter(std::shared_ptr<Formatter> formatter)
{
    this->formatter = std::move(formatter);
}

} // namespace WW
