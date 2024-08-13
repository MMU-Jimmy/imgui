#include "Logging/Console.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h> // For colored console logging

void Console::Init()
{
    GetEngineLogger().set_level(spdlog::level::info);
    GetEngineLogger().set_pattern("%^[{cyan}%T] %n: %v%$");
}

spdlog::logger& Console::GetEngineLogger()
{
    static spdlog::logger engineLogger("ENGINE", std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    return engineLogger;
}

