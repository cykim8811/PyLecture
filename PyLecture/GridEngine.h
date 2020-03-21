#pragma once
#include "Engine.h"
#include "SDL.h"
#include <iostream>
#include "call.h"

using namespace std;

class GridEngine :public Engine
{
public:
	void Tick(float dT);
	void Draw(SDL_Renderer* renderer);
	int Event(SDL_Event event);
	char* Command(int cmd, vector<int> args);

	char* get_name() { return "Grid"; }
	int get_width() { return 32 * 30; }
	int get_height() { return 32 * 20; }
	
	int data[30 * 20]{ 0 };
	float display[30 * 20]{ 0 };
};

extern vector<call> call_list;