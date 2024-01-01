#pragma once

#include <SDL.h>
#include <stdio.h>

class BaseManager
{
public:
	virtual bool init() = 0;
	virtual void close() = 0;
	virtual void* get() = 0;
};