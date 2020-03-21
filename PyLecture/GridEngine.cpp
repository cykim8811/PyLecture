#include "GridEngine.h"


void GridEngine::Tick(float dT) {
	for (int x = 0; x < 30; x++) {
		for (int y = 0; y < 20; y++) {
			float ratio = 0.6;
			display[x + y * 30] += (data[x + y * 30] - display[x + y * 30]) * ratio;
		}
	}
}

void GridEngine::Draw(SDL_Renderer* renderer) {
	SDL_Rect rect;
	float blink = (0.3 * (rand() % 100) / 100 - 0.3);
	for (int x = 0; x < 30; x++) {
		for (int y = 0; y < 20; y++) {
			float value = display[x + y * 30] + display[x + y * 30] * blink;
			int r = int(230 + (64 - 230) * value),
				g = int(230 + (255 - 230) * value),
				b = int(230 + (112 - 230) * value);
			SDL_SetRenderDrawColor(renderer, r, g, b, 255);
			rect = { x * 32, y * 32, 32, 32 };
			SDL_RenderFillRect(renderer, &rect);
		}
	}
	for (int x = 0; x < 30; x++) {
		SDL_SetRenderDrawColor(renderer, 210, 210, 210, 255);
		SDL_RenderDrawLine(renderer, x * 32 - 1, 0, x * 32 - 1, 32 * 20);
		SDL_SetRenderDrawColor(renderer, 190, 190, 190, 255);
		SDL_RenderDrawLine(renderer, x * 32, 0, x * 32, 32 * 20);
	}
	for (int y = 0; y < 20; y++) {
		SDL_SetRenderDrawColor(renderer, 210, 210, 210, 255);
		SDL_RenderDrawLine(renderer, 0, y * 32 - 1, 32 * 30, y * 32 - 1);
		SDL_SetRenderDrawColor(renderer, 190, 190, 190, 255);
		SDL_RenderDrawLine(renderer, 0, y * 32, 32 * 30, y * 32);
	}
}

int GridEngine::Event(SDL_Event event) {
	if (event.type == SDL_QUIT) {
		return -1;
	}

	return 0;
}

char* GridEngine::Command(char* cmd, vector<int> args) {
	if (cmd == "on") {
		int x = args[0],
			y = args[1];
		if (x<0 || x>30 || y<0 || y>20) {
			return "[Error]out of screen";
		}
		data[x + y * 30] = 1;
	}

	return cmd;
}