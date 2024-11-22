#pragma once
#include "Ghost.h"
#include "AStarSearch.h"

class Blinky : public Ghost
{
	public:
		Blinky(int r, int c, SDL_Renderer* renderer, SDL_Texture* spritesheet, PacMan* player, Board* board) : Ghost(r, c, renderer, spritesheet, player, board) {}
		void renderGhost() override;
		void updateGhost() override;

};