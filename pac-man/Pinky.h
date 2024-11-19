#pragma once
#include "Ghost.h"

class Pinky : public Ghost
{
public:
	Pinky(int r, int c, SDL_Renderer* renderer, SDL_Texture* spritesheet) : Ghost(r, c, renderer, spritesheet) {}
	void renderGhost() override;
};
