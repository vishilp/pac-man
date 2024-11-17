#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"
#include "globals.h"

class PacMan {
	public:
		PacMan(int row, int col); //how does inheritance work with constructors?
		~PacMan();
		bool isAlive();
		void movePacMan(int dir); //in pixels
		void updateRowsorCols(int dir); 
		int Row() { return row; } //in the array, NOT in pixels
		int Col() { return col; }
		int pixelX() { return pixelx; }
		int pixelY() { return pixely; }
		void setDirection(int dir);
		int getDirection();

	private:
		bool alive = true;
		int row;
		int col;
		int pixelx;
		int pixely;
		int direction;
};

//update his sprite in game::renderPacman