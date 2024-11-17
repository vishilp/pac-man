#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"

class PacMan {
	public:
		PacMan(int row, int col); //how does inheritance work with constructors?
		~PacMan();
		bool isAlive();
		void movePacMan(int dir);
		int Row() { return row; } //in the array, NOT in pixels
		int Col() { return col; }
		int pixelX() { return pixelx; }
		int pixelY() { return pixely; }

	private:
		bool alive = true;
		int row;
		int col;
		int pixelx;
		int pixely;
};
