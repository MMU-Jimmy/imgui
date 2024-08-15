#pragma once

#include "Object.h"
#include "../Components/Component.h"
#include <vector>
#include <cinttypes>

using namespace std;

class Scene
{
	vector<Object*> objectList;
public:
	uint32_t GetNumObjects() { return objectList.size(); }
	Object* GetObject(uint32_t i) { return objectList[i]; }
	void AddObject(Object* obj);
	void RemoveObject(Object* obj);
	void RemoveObject(uint32_t index);
	void OnUpdate(float deltaTime);
};