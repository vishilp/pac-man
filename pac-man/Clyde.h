#pragma once
#include "Ghost.h"

class Clyde : public Ghost
{
public:
	Clyde(int r, int c, SDL_Renderer* renderer, SDL_Texture* spritesheet) : Ghost(r, c, renderer, spritesheet) {}
	void renderGhost() override;
};
