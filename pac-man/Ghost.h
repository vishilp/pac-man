#pragma once
#include "globals.h"
#include <SDL.h>
#include "TextureManager.h"
#include "PacMan.h"
#include "Board.h"
#include "AStarSearch.h"

class Ghost {
	public:
		Ghost(int r, int c, SDL_Renderer* renderer, SDL_Texture* spritesheet, PacMan* player, Board* board);
		bool isAlive();
		int getRow(); //in the array, NOT in pixels
		int getCol();
		void setRow(int r);
		void setCol(int c);
		void updateRowsorCols();
		float pixelX() { return pixelx; }
		float pixelY() { return pixely; }
		bool chaseMode() { return chasemode; }
		void virtual renderGhost() {} //will be overridden by every ghost
		void virtual updateGhost() {}
		void moveGhost();
		int getDirection() { return direction; }
		void setDirection(int dir) {direction = dir;}
		bool isOnPacMan();
		SDL_Renderer* ren = nullptr;
		SDL_Texture* sprites = nullptr;
		PacMan* player = nullptr;
		Board* map = nullptr;
		int getSpeed() { return speed; }

		void translateNodeToDir(Node node);
		bool moving;
		void setChaseMode(bool mode) { chasemode = mode; }

	private:
		bool alive;
		int row;
		int col;
		float pixelx;
		float pixely;
		int direction;
		bool chasemode = true;  //chase, scatter, killable
		int speed = 8; //must be divisible by 16 for it to work perfectly
		//speed is 10x actual value for floating point precision reasons, divided by 10 later


};
