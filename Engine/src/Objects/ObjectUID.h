#pragma once
#include <cinttypes>

class ObjectUID
{
	static uint32_t curUid;
public:
	static uint32_t UID() { return curUid++; }
};