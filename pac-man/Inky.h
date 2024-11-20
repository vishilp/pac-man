#pragma once
#include "Ghost.h"

class Inky : public Ghost
{
public:
	Inky(int r, int c, SDL_Renderer* renderer, SDL_Texture* spritesheet) : Ghost(r, c, renderer, spritesheet) {}
	void renderGhost() override;
};