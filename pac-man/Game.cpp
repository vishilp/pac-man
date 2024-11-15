#include "Game.h"

SDL_Texture* board;

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
	}
	else
		isRunning = false;
}

void Game::loadBoard() {

	if (IMG_Init(IMG_INIT_PNG) != 0 && isRunning) {
		SDL_Surface* tempSurface = IMG_Load("assets/board.png");
		board = SDL_CreateTextureFromSurface(renderer, tempSurface);
		SDL_FreeSurface(tempSurface);
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
	SDL_RenderCopy(renderer, board, NULL, NULL); //render whole board png

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::running() { return isRunning; }

