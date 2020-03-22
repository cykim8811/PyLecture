#pragma once
#include "Engine.h"
#include "SDL.h"
#include <iostream>
#include "call.h"

class Arrow {
	int x, y, dir;

};

using namespace std;

const int w = 40, h = 30;

class ArrowEngine :public Engine
{
public:
	void Tick(float dT);
	void Draw(SDL_Renderer* renderer);
	int Event(SDL_Event event);
	int Command(int cmd, vector<int> args);

	char* get_name() { return "Grid"; }
	int get_width() { return 32 * w; }
	int get_height() { return 32 * h; }

	bool data[w * h]{ 1 };
};

extern vector<call> call_list;

