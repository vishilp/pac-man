#pragma once
#include "Ghost.h"

class Inky : public Ghost
{
public:
	Inky(int r, int c, SDL_Renderer* renderer, SDL_Texture* spritesheet, PacMan* player, Board* board) : Ghost(r, c, renderer, spritesheet, player, board) {}
	void renderGhost() override;
};