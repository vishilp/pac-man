#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"

class PacMan {
	public:
		PacMan(int row, int col); //how does inheritance work with constructors?
		~PacMan();
		bool isAlive();
		void movePacMan();
		int Row() { return row; } //in the array, NOT in pixels
		int Col() { return col; }

	private:
		bool alive = true;
		int row;
		int col;
};
