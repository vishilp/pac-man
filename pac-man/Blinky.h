#pragma once
#include "Ghost.h"

class Blinky : public Ghost
{
	public:
		Blinky(int r, int c, SDL_Renderer* renderer, SDL_Texture* spritesheet, PacMan* player) : Ghost(r, c, renderer, spritesheet, player) {}
		void renderGhost() override;
		void updateGhost() override;
};