#pragma once

#include <string>
#include <cinttypes>

#include "ObjectUID.h"
using namespace std;

class Component
{
	// abstract base class
	string type;
	uint32_t uid;
public:
	Component() : type("default"), uid(ObjectUID::UID()) {}
	virtual ~Component(); 

	string GetType() const { return type; }
	
	virtual void OnStart() = 0;
	virtual void OnUpdate(float deltaTime) = 0;
	virtual void OnRender() = 0;

};