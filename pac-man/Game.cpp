#include "Game.h"
#include "TextureManager.h"
#include "Board.h"

Board* map = new Board();
SDL_Texture* wallsheet;

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		}
		isRunning = true;
		IMG_Init(IMG_INIT_PNG);
	}
	else
		isRunning = false;

	
}

void Game::loadBoard() {

	wallsheet= TextureManager::LoadTexture("assets/walls.png", renderer);
	for (int i = 0; i < map->width; i++)
	{
		char walltype = map->board1[0][i];
		SDL_Rect dest = { i * TextureManager::SpriteWidth, 0, TextureManager::SpriteWidth, TextureManager::SpriteHeight };
		switch (walltype)
		{
			case 'r':
				SDL_RenderCopy(renderer, wallsheet, TextureManager::ReturnSpriteRect('r'), &dest);
				break;
			case '#':
				SDL_RenderCopy(renderer, wallsheet, TextureManager::ReturnSpriteRect('#'), &dest);
				break;

		}



	}
}


void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::update() {

}

void Game::render() {
	SDL_RenderClear(renderer);
	//add stuff for rendering
	loadBoard();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyTexture(wallsheet);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	IMG_Quit();
	SDL_Quit();
	delete map;
}

bool Game::running() { return isRunning; }

