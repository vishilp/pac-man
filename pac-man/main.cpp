#include <SDL.h>
#undef main

#include "Game.h"


const int SCREEN_WIDTH = 452;
const int SCREEN_HEIGHT = 496;

Game* game = nullptr;

int main(){
	const int FPS = 60;
	const int FrameDelay = 1000 / FPS;
	Uint32 FrameStart;
	int FrameTime;

	game = new Game();
	game->init("Pac-Man", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->loadBoard();

	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();
	delete game;

	//board and sprites scaled to 150%

	return 0;
};