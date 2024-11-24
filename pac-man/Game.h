#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"
#include "PacMan.h"
#include "Board.h"
#include "Dot.h"
#include "globals.h"
#include "Blinky.h"
#include "Pinky.h"
#include "Inky.h"
#include "Clyde.h"

class Game {
	
	public:
		Game();
		~Game();

		void init(const char* title, int xpos, int ypos, int width, int height);

		void loadBoardTexture(); 
		void updatePacMan(); //no longer necessary

		void handleEvents();
		void handlePacManMovement(int dir); //movement frame by frame
		void update();
		void render();
		void clean(); 
		bool running();
		
		SDL_Texture* wallsheet;
		SDL_Texture* boardTexture;
		SDL_Texture* spritesheet;

	private:
		bool isRunning =false;
		SDL_Window* window =nullptr;
		SDL_Renderer* renderer =nullptr;
		PacMan* player = nullptr;
		Board* map = nullptr;
		int ghostcount = 4;
		Ghost* ghosts[4];
};

