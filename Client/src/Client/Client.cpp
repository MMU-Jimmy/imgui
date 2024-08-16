#include <EngineIncludes.h>

namespace ClientApp
{
	class Client :public IonixEngine::Application
	{
	public:
		Client()
		{

		}
		~Client()
		{

		}
	};

	IonixEngine::Application* CreateApplication()
	{
		Console::GetEngineLogger().info("Application Created.");

		return new Client();
	}
}

