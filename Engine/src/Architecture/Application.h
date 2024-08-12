#pragma once
#include "Macros.h"

class ENGINE_API Application
{
public:
    Application();
    virtual ~Application();

    void Run();

private:
    bool m_Running = true;
};

Application* CreateApplication();
