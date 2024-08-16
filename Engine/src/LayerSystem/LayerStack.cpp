#include "LayerStack.h"

namespace IonixEngine
{
    LayerStack::LayerStack() {}

    LayerStack::~LayerStack() 
    {
        for (auto layer : m_Layers)
            delete layer;
        m_Layers.clear();
    }

    void LayerStack::PushLayer(Layer* layer) 
    {
        m_Layers.push_back(layer);
    }

    void LayerStack::PopLayer(Layer* layer) 
    {
        for (auto it = m_Layers.begin(); it != m_Layers.end(); ++it) 
        {
            if (*it == layer) 
            {
                m_Layers.erase(it);
                delete layer;
                break;
            }
        }
    }

    Layer* LayerStack::GetLayerByID(int id)
    {
        for (Layer* layer : m_Layers)
        {
            if (layer->GetID() == id)
            {
                return layer;
            }
        }

        return nullptr;
    }
}

