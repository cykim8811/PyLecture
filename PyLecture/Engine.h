#pragma once
#include "SDL.h"
#include "Python.h"
#include <iostream>
#include <vector>

using namespace std;

class Engine
{
public:
	virtual void Tick(float dT) {}
	virtual void Draw(SDL_Renderer* renderer) {}
	virtual int Event(SDL_Event ev) { return -1; }
	virtual char* Command(int cmd, vector<int> args) { return "NULL"; }

	virtual char* get_name() { return "NULL"; }
	virtual int get_width() { return 640; }
	virtual int get_height() { return 480; }
};

