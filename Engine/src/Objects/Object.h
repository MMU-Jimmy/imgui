#pragma once
#include <vector>
#include <cinttypes>
#include "ObjectUID.h"
using namespace std;
class Component; // forward declaration

class Object
{
	uint32_t uid;
	vector<Component*> components;
public:
	Object() : uid(ObjectUID::UID()) {}
	~Object()
	{
		// delete all the components
		for (auto c : components)
			delete c;
	}
	void AddComponent(Component* comp);
	void RemoveComponent(Component* comp);
	void RemoveComponent(uint32_t index);


	uint32_t GetNumComponents() const { return components.size(); }
	Component* GetComponent(uint32_t index) const { return components[index]; }
};