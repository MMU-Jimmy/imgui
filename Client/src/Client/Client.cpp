#pragma once
#include <Libs.h>

class Client :public Application
{
public:
	Client()
	{

	}
	~Client()
	{

	}
};

Application* CreateApplication()
{
	// Example log from client side
	Console::GetClientLogger().info("Test");

	return new Client();
}
