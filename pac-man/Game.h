#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"

class Game {
	
	public:
		Game();
		~Game();

		void init(const char* title, int xpos, int ypos, int width, int height);

		void loadBoard();

		void handleEvents();
		void update();
		void render();
		void clean(); 
		bool running();

	private:
		bool isRunning =false;
		SDL_Window* window =nullptr;
		SDL_Renderer* renderer =nullptr;
};

