#include <EngineIncludes.h>

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
	Console::GetEngineLogger().info("Application Created.");

	return new Client();
}
