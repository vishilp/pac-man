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

	std::pair<int, int> homeZone[34] = { //row, col
		{29,1}, {29,2}, {29,3}, {29,4}, {29,5}, {29,6}, {29,7}, {29,8}, {29,9}, {29,10}, {29,11}, {29, 12},
		{28,12}, {27,12}, {26, 12}, {26, 11}, {26, 10}, {26, 9}, {25, 9}, {24, 9}, {23,9}, {23,8}, {23,7}, {23,6},
		{24,6}, {25, 6}, {26, 6}, {26, 5}, {26, 4}, {26, 3}, {26, 2}, {26,1}, {27, 1}, {28, 1}
	};
};
