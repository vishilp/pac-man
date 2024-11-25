#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"
#include "globals.h"
#include <cmath>

class PacMan{
	public:
		PacMan(int row, int col, SDL_Renderer* renderer, SDL_Texture* spritesheet); //how does inheritance work with constructors?
		~PacMan();
		bool isAlive() { return alive; }
		void movePacMan(int dir); //in pixels
		bool updateRowsorCols(); 
		int Row() { return row; } //in the array, NOT in pixels
		int Col() { return col; }
		float pixelX() { return pixelx; }
		float pixelY() { return pixely; }
		void setDirection(int dir);
		int getDirection();
		void renderPacMan();
		bool isSwitchableX() { return switchablex; }
		bool isSwitchableY() {return switchabley;}
		float pacSpeed = 1.0f;

	private:
		bool alive = true;
		bool switchablex; //if his dir can be switched left or right
		bool switchabley; 
		int row;
		int col;
		float pixelx;
		float pixely;
		int direction;
		SDL_Renderer* ren = nullptr;
		SDL_Texture* sprites = nullptr;
};