#pragma once
#include "Architecture/Macros.h"
#include "Layer.h"
#include <vector>

namespace IonixEngine
{
	class ENGINE_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		Layer* GetLayerByID(int id);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
	};
}



