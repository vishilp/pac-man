#pragma once
#include "Ghost.h"

class Clyde : public Ghost
{
public:
	Clyde(int r, int c, SDL_Renderer* renderer, SDL_Texture* spritesheet, PacMan* player, Board* board) : Ghost(r, c, renderer, spritesheet, player, board) {}
	void renderGhost() override;
	void updateGhost() override;
	void shyModeMove();
	//if within 8 tiles of pacman, goes to shy mode where he hovers near bottom left. If further than 8 tiles, chase pacman
};
