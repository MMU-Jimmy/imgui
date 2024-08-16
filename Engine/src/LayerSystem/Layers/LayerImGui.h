#pragma once
#include "LayerSystem/Layer.h"
#include "Logging/Console.h"

namespace IonixEngine
{
	class LayerImGui : public Layer
	{
	public: 
		using Layer::Layer;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnEvent(Event& e) override;
	};
}
