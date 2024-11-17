#include <SDL.h>
#undef main

#include "Game.h"


const int SCREEN_WIDTH = 448;
const int SCREEN_HEIGHT = 496;

Game* game = nullptr;

int main(){
	const int FPS = 30;
	const int FrameDelay = 1000 / FPS; //time between frames in ms
	Uint32 FrameStart;
	int FrameTime;

	game = new Game();
	game->init("Pac-Man", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT);

	while (game->running())
	{
		FrameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		FrameTime = SDL_GetTicks() - FrameStart;

		if (FrameDelay > FrameTime)
		{
			SDL_Delay(FrameDelay - FrameTime);
		}
	}

	game->clean();
	delete game;


	return 0;
};