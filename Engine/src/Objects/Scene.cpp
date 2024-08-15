#include "Scene.h"

void Scene::AddObject(Object* obj)
{
	objectList.push_back(obj);
}

void Scene::RemoveObject(Object* obj)
{
	auto it = objectList.begin();
	while (it != objectList.end())
	{
		if (*it == obj)
		{
			it = objectList.erase(it);
		}
		else
			++it;
	}
	delete obj;

}
void Scene::RemoveObject(uint32_t index)
{
	objectList.erase(objectList.begin() + index);
}

void Scene::OnUpdate(float deltaTime)
{
	for (auto o : objectList)
	{
		for (uint32_t i = 0; i < o->GetNumComponents(); i++)
		{
			o->GetComponent(i)->OnUpdate(deltaTime);
		}
	}
}
