#include "SinkBase.h"

namespace WW
{

SinkBase::SinkBase(std::shared_ptr<FormatterBase> formatter)
    : formatter(std::move(formatter))
{
}

void SinkBase::setFormatter(std::shared_ptr<FormatterBase> formatter)
{
    this->formatter = std::move(formatter);
}

} // namespace WW
