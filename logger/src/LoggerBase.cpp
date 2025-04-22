#include "LoggerBase.h"

namespace WW
{

void LoggerBase::addSink(std::shared_ptr<Sink> sink)
{
    sinks.emplace_back(std::move(sink));
}

} // namespace WW
