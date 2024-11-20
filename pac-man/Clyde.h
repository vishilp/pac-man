#pragma once
#include "Ghost.h"

class Clyde : public Ghost
{
public:
	Clyde(int r, int c, SDL_Renderer* renderer, SDL_Texture* spritesheet, PacMan* player) : Ghost(r, c, renderer, spritesheet, player) {}
	void renderGhost() override;
};
