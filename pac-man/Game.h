#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"
#include "PacMan.h"
#include "Board.h"
#include "Dot.h"
#include "globals.h"

class Game {
	
	public:
		Game();
		~Game();

		void init(const char* title, int xpos, int ypos, int width, int height);

		void loadBoard(); //run it once

		void handleEvents();
		void update();
		void render();
		void clean(); 
		bool running();
		
		SDL_Texture* wallsheet;

	private:
		bool isRunning =false;
		SDL_Window* window =nullptr;
		SDL_Renderer* renderer =nullptr;
		PacMan* player = nullptr;
		Board* map = nullptr;
};

