#include "LayerImGui.h"

namespace IonixEngine
{
	void LayerImGui::OnAttach()
	{
		// Initialize OnGUI
	}

	void LayerImGui::OnDetach()
	{
		// Clean up resources
	}

	void LayerImGui::OnUpdate()
	{
		Console::GetEngineLogger().info("Layer: ImGui - Updated.");
	}

	void LayerImGui::OnEvent(Event& e)
	{
		Console::GetEngineLogger().info(e.GetInfo());
	}
}

