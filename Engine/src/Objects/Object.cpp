#include "Object.h"
#include "../Components/Component.h"

void Object::AddComponent(Component* comp)
{
	components.push_back(comp);
	comp->OnStart(); // call OnStart when component is added to object. This could be managed better so it is called on first update?
}

void Object::RemoveComponent(Component* comp)
{
	auto it = components.begin();
	while (it != components.end())
	{
		if (*it == comp)
		{
			it = components.erase(it);
			break;
		}
		else
			++it;
	}
	delete comp;
}

void Object::RemoveComponent(uint32_t index)
{
	Component* comp = components[index];
	components.erase(components.begin() + index);
	delete comp;
}

