#pragma once
#include "Ghost.h"

class Blinky : public Ghost
{
	public:
		Blinky(int r, int c, SDL_Renderer* renderer, SDL_Texture* spritesheet) : Ghost(r, c, renderer, spritesheet) {}
		void renderGhost() override;
};