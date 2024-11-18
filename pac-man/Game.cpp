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
	player = new PacMan(23,13);

	
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

}

void Game::renderPacMan()
{
	SDL_RenderClear(renderer);
	loadBoard();
	SDL_Texture* pacman = TextureManager::LoadTexture("assets/PacManSprites.png", renderer);
	SDL_Rect spawnpoint = { player->pixelX(), player->pixelY(), TextureManager::SpriteWidth, TextureManager::SpriteHeight};
	SDL_RenderCopy(renderer, pacman, TextureManager::ReturnPacmanRect(), &spawnpoint);

}

void Game::updatePacMan(int direction)
{
	if (direction == RIGHT)
	{
		//GET THIS TO KEEP MOVING UNTIL WALL OR DIR CHANGE
		while (map->isValidMove(player))
		{
			for (int i = 0; i < TextureManager::SpriteWidth; i++)
			{
					player->movePacMan(RIGHT);
					renderPacMan();
					SDL_RenderPresent(renderer); //renderer() if this doesn't work
			}
			map->movePacMan(RIGHT, player->Row(), player->Col());
			player->updateRowsorCols(RIGHT);
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
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
				case SDLK_RIGHT:
					player->setDirection(RIGHT);
					updatePacMan(RIGHT);
					break; 
				case SDLK_LEFT:
					player->setDirection(LEFT);
					updatePacMan(LEFT);
					break;
				case SDLK_UP:
					player->setDirection(UP);
					updatePacMan(UP);
					break;
				case SDLK_DOWN:
					player->setDirection(DOWN);
					updatePacMan(DOWN);
					break;
			}
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
	renderPacMan();
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

