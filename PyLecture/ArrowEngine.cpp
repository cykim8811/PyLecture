#include "ArrowEngine.h"


void ArrowEngine::Tick(float dT) {

}

void ArrowEngine::Draw(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_Rect rect;
	const int offset = 2;
	for (int x = 0; x < w; x++) {
		for (int y = 0; y < h; y++) {
			if (!data[x + y * w]) continue;
			SDL_SetRenderDrawColor(renderer, 250, 250, 250, 255);
			rect = { x * 32 + offset, y * 32 + offset, 32 - offset * 2, 32 - offset * 2 };
			SDL_RenderFillRect(renderer, &rect);
		}
	}
}

int ArrowEngine::Event(SDL_Event event) {
	if (event.type == SDL_QUIT) {
		return -1;
	}

	return 0;
}

int ArrowEngine::Command(int cmd, vector<int> args) {

	return 0;
}