#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"
#include "globals.h"

class PacMan{
	public:
		PacMan(int row, int col, SDL_Renderer* renderer, SDL_Texture* spritesheet); //how does inheritance work with constructors?
		~PacMan();
		bool isAlive() { return alive; }
		void movePacMan(int dir); //in pixels
		void updateRowsorCols(int dir); 
		int Row() { return row; } //in the array, NOT in pixels
		int Col() { return col; }
		int pixelX() { return pixelx; }
		int pixelY() { return pixely; }
		void setDirection(int dir);
		int getDirection();
		void renderPacMan();
		float pacSpeed = 0.1f;

	private:
		bool alive = true;
		int row;
		int col;
		float pixelx;
		float pixely;
		int direction;
		SDL_Renderer* ren = nullptr;
		SDL_Texture* sprites = nullptr;
};