#pragma once
#include "Ghost.h"

class Inky : public Ghost
{
public:
	Inky(int r, int c, SDL_Renderer* renderer, SDL_Texture* spritesheet, PacMan* player, Board* board, Ghost* Blinky) : Ghost(r, c, renderer, spritesheet, player, board, Blinky) {}
	void renderGhost() override;
	void updateGhost() override;

private:
	std::vector<Node> nodes;

	//target is 2 tiles ahead of pacman, blinky vector to that tile, multiplied by two
};