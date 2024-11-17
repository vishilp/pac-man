#include "Game.h"



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
	map = new Board();
	player = new PacMan(0, 0);

	
}

void Game::loadBoard() {

	wallsheet= TextureManager::LoadTexture("assets/walls.png", renderer);
	for (int i = 0; i < map->width; i++)
	{
		for (int j = 0; j < map->height; j++)
		{
			int walltype = map->board1[j][i];
			SDL_Rect dest = { i * TextureManager::SpriteWidth, j * TextureManager::SpriteHeight, TextureManager::SpriteWidth, TextureManager::SpriteHeight };
			SDL_Rect* spriterect = TextureManager::ReturnSpriteRect(walltype);
			if (walltype == 46) //for dots
			{
				Dot dot = Dot(renderer, wallsheet, spriterect, &dest);
				continue;
			}
			else
				SDL_RenderCopy(renderer, wallsheet, spriterect, &dest);
		}

	}
	if (player->isAlive())
	{
		SDL_Texture* pacman = TextureManager::LoadTexture("assets/PacManSprites.png", renderer);
		SDL_Rect spawnpoint = { 16, 16, TextureManager::SpriteWidth, TextureManager::SpriteHeight };
		SDL_RenderCopy(renderer, pacman, TextureManager::ReturnPacmanRect(), &spawnpoint);
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
	delete player;
}

bool Game::running() { return isRunning; }

