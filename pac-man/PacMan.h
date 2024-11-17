#pragma once
#include <SDL.h>
#include <SDL_image.h>

class PacMan {
	public:
		PacMan(int x, int y); //how does inheritance work with constructors?
		~PacMan();
		bool isAlive();
	private:
		bool alive = true;
		int posx;
		int posy;
};
