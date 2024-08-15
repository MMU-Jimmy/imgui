#pragma once

#include <string>
#include <cinttypes>
#include "Component.h"
#include <vector>

using namespace std;

class TransformComponent : public Component
{
	TransformComponent* parent = nullptr;
	vector<TransformComponent*> children;
public:
	// probably a vector2d class would be a good idea. Making these public because getters and setters wouldn't do anything other
	// that get and set
	float x, y; // position
	float sx, sy; // scale
	float angle; // rotation

	TransformComponent() : Component("Transform") 
	{
	}
	virtual ~TransformComponent() {}

	virtual void OnStart()
	{

	}
	virtual void OnUpdate(float deltaTime)
	{

	}
	virtual void OnRender()
	{

	}
	// methods specific to TransformComponent
	void SetParent(TransformComponent* p) { parent = p; }
	void AddChild(TransformComponent* c) { children.push_back(c); }
	TransformComponent* GetChild(uint32_t i) const { return children[i]; }
	uint32_t GetNumChildren() const { return children.size(); }
};