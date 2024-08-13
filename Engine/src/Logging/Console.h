#pragma once

#include <Architecture/Macros.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

class ENGINE_API Console
{
public:
    static void Init();

    static spdlog::logger& GetEngineLogger();
};
