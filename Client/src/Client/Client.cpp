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
	return new Client();
}
