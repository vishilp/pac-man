#pragma once
#include "globals.h"
#include <SDL.h>
#include "TextureManager.h"
#include "PacMan.h"

class Ghost {
	public:
		Ghost(int r, int c, SDL_Renderer* renderer, SDL_Texture* spritesheet, PacMan* player);
		bool isAlive();
		int getRow(); //in the array, NOT in pixels
		int getCol();
		void setRow(int r);
		void setCol(int c);
		void updateRowsorCols(int dir);
		int pixelX() { return pixelx; }
		int pixelY() { return pixely; }
		int ghostMode() { return mode; }
		void virtual renderGhost() {} //will be overridden by every ghost
		void virtual updateGhost() {}
		SDL_Renderer* ren = nullptr;
		SDL_Texture* sprites = nullptr;
		PacMan* player = nullptr;

	private:
		bool alive;
		int row;
		int col;
		float pixelx;
		float pixely;
		int direction;
		int mode;  //chase, scatter, killable


};
