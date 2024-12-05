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
	wallsheet = TextureManager::LoadTexture("assets/walls.png", renderer);
	loadBoardTexture();

	spritesheet = TextureManager::LoadTexture("assets/PacManSprites.png", renderer);
	player = new PacMan(SPAWNROW,SPAWNCOL, renderer, spritesheet);
	ghosts[0] = new Blinky(11,14, renderer, spritesheet, player, map);
	ghosts[1] = new Pinky(14, 14, renderer, spritesheet, player, map);
	ghosts[2] = new Inky(14, 12, renderer, spritesheet, player, map, ghosts[0]);
	ghosts[3] = new Clyde(14, 16, renderer, spritesheet, player, map);
	
}



void Game::loadBoardTexture() {
	dotCount = 0;
	boardTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_SetRenderTarget(renderer, boardTexture);

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
				dotCount += 1;
				continue;
			}
			else
				SDL_RenderCopy(renderer, wallsheet, spriterect, &dest);

		}

	}

	map->setDotCount(dotCount);
	SDL_SetRenderTarget(renderer, NULL);
}





void Game::updatePacMan()  //OLD FUNCTION, NO LONGER NECESSARY
{
	int tiletype = 0;
	if (!map->isValidMove(player, player->getDirection()))
		return;
	if (player->getDirection() == RIGHT)
	{
		for (int i = 0; i < (TextureManager::SpriteWidth)/player->pacSpeed; i++)
		{
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, boardTexture, NULL, NULL);
			player->movePacMan(RIGHT);
			player->renderPacMan();
			for (int i = 0; i < ghostcount; i++)
				ghosts[i]->renderGhost();
			SDL_RenderPresent(renderer); 
		}
		tiletype = map->movePacMan(RIGHT, player->Row(), player->Col());
		if (tiletype ==DOTTILE)
			loadBoardTexture();
		//player->updateRowsorCols(RIGHT);
		ghosts[0]->updateGhost();
	}

	if (player->getDirection() == LEFT)
	{
		for (int i = 0; i < TextureManager::SpriteWidth / player->pacSpeed; i++)
		{
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, boardTexture, NULL, NULL);
			player->movePacMan(LEFT);
			player->renderPacMan();
			for (int i = 0; i < ghostcount; i++)
				ghosts[i]->renderGhost();
			SDL_RenderPresent(renderer); 
		}
		tiletype = map->movePacMan(LEFT, player->Row(), player->Col());
		if (tiletype == DOTTILE)
			loadBoardTexture();
		//player->updateRowsorCols(LEFT);
		ghosts[0]->updateGhost();
	}

	if (player->getDirection() == UP)
	{
		for (int i = 0; i < TextureManager::SpriteWidth / player->pacSpeed; i++)
		{
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, boardTexture, NULL, NULL);
			player->movePacMan(UP);
			player->renderPacMan();
			for (int i = 0; i < ghostcount; i++)
				ghosts[i]->renderGhost();
			SDL_RenderPresent(renderer); 
		}
		tiletype = map->movePacMan(UP, player->Row(), player->Col());
		if (tiletype == DOTTILE)
			loadBoardTexture();
		//player->updateRowsorCols(UP);
		ghosts[0]->updateGhost();
	}

	if (player->getDirection() == DOWN)
	{
		for (int i = 0; i < TextureManager::SpriteWidth / player->pacSpeed; i++)
		{
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, boardTexture, NULL, NULL);
			player->movePacMan(DOWN);
			player->renderPacMan();
			for (int i = 0; i < ghostcount; i++)
				ghosts[i]->renderGhost();
			SDL_RenderPresent(renderer); 
		}
		tiletype = map->movePacMan(DOWN, player->Row(), player->Col());
		if (tiletype == DOTTILE)
			loadBoardTexture();
		//player->updateRowsorCols(DOWN);
		ghosts[0]->updateGhost();
	}
	
}




void Game::handleEvents() {

	//maybe have a stack of inputs, with it being cleared after a few ms of delay

	SDL_Event event;
	SDL_PollEvent(&event);
	int currentdir = player->getDirection();

	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
				case SDLK_RIGHT:
					player->setQueuedDirection(RIGHT);
					break;
				case SDLK_LEFT:
					player->setQueuedDirection(LEFT);
					break;
				case SDLK_UP:
					player->setQueuedDirection(UP);
					break;
				case SDLK_DOWN:
					player->setQueuedDirection(DOWN);
					break;
			}
		default:
			break;
	}


}

void Game::handlePacManMovement()
{
	if (map->isValidMove(player, player->getQueuedDirection()))  //if queued direction is valid move
	{
		player->setDirection(); //update direction based on queued actions
	}
	else //increment queued frames
	{
		player->incremementQueuedFrames();
	}

	int dir = player->getDirection(); //keep going in original direction if its valid move
	if (!map->isValidMove(player, dir))
		return;
	
	int tiletype = 0;
	
	player->movePacMan(dir);
	player->renderPacMan();
	bool changed = player->updateRowsorCols();
	if (changed)
	{
		switch (dir)
		{
			case 1: //LEFT
				tiletype = map->movePacMan(LEFT, player->Row(), player->Col() + 1);
				//pass in col()+1 bcuz pacmans cols were just decrememnted by 1 (to go left)
				break;
			case 2:   //RIGHT
				tiletype = map->movePacMan(RIGHT, player->Row(), player->Col() - 1);
				break;
			case 3:   //UP
				tiletype = map->movePacMan(UP, player->Row() + 1, player->Col());
				break;
			case 4:   //DOWN
				tiletype = map->movePacMan(DOWN, player->Row() - 1, player->Col());
				break;
		}
		if (tiletype == DOTTILE)
			loadBoardTexture();
	}
}

void Game::update() {
	//need to update the ghost and pacman at the same time
	if (player->isAlive())
		handlePacManMovement();
	else
		resetGame();
	//do same thing for ghosts, only do A* when pacman is at new cell
	for (int i = 0; i < ghostcount; i++)
		ghosts[i]->updateGhost();

	
}

void Game::resetGame()
{
	SDL_RenderClear(renderer);


	SDL_RenderPresent(renderer);
	SDL_Delay(500);
}

void Game::render() {
	SDL_RenderClear(renderer);
	//add stuff for rendering
	SDL_RenderCopy(renderer, boardTexture, NULL, NULL);
	player->renderPacMan();
	for (int i = 0; i < ghostcount; i++)
		ghosts[i]->renderGhost();
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
	for (int i = 0; i < ghostcount; i++)
		delete ghosts[i];
}

bool Game::running() { return isRunning; }

