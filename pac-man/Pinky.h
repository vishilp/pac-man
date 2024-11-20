#pragma once
#include "Ghost.h"

class Pinky : public Ghost
{
public:
	Pinky(int r, int c, SDL_Renderer* renderer, SDL_Texture* spritesheet, PacMan* player, Board* board) : Ghost(r, c, renderer, spritesheet, player, board) {}
	void renderGhost() override;
};
