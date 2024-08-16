#include "LayerExample.h"

namespace IonixEngine
{
	void LayerExample::OnAttach()
	{
		// Initialize ExampleLayer
	}

	void LayerExample::OnDetach()
	{
		// Clean up resources
	}

	void LayerExample::OnUpdate()
	{
		Console::GetEngineLogger().info("Layer: Example - Updated.");
	}

	void LayerExample::OnEvent(Event& e)
	{
		Console::GetEngineLogger().info(e.GetInfo());
	}
}

