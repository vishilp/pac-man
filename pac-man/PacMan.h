#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"

class PacMan {
	public:
		PacMan(int x, int y); //how does inheritance work with constructors?
		~PacMan();
		bool isAlive();
		void movePacMan();
		int posX() { return posx; }
		int posY() { return posy; }

	private:
		bool alive = true;
		int posx;
		int posy;
};
