#include "Inky.h"

void Inky::renderGhost()
{
	SDL_Rect location = { pixelX(), pixelY(), TextureManager::SpriteWidth, TextureManager::SpriteHeight };
	SDL_RenderCopy(ren, sprites, TextureManager::ReturnInkyRect(), &location);
}

void Inky::updateGhost()
{
	if (isOnPacMan())
		return;

	if (nodes.empty()) { //go to endpoint before running A* again
		int dir = player->getDirection();
		int row = player->Row();
		int col = player->Col();

		switch (dir)
		{
		case 1:
			col -= 2;
			break;
		case 2:
			col += 2;
			break;
		case 3:
			row -= 2;
			break;
		case 4:
			row += 2;
			break;
		default:   // just follow pacman's current tile
		}

		int rowvector = 2 * (blinky->getRow() - row);  //vectors from blinky's position to "ahead" tile, and then doubled
		int colvector = 2 * (blinky->getCol() - col);
		int targetrow = blinky->getRow() - rowvector;
		int targetcol = blinky->getCol() - colvector;

		moving = true;
		NodeManager manager;
		Node Inky(getRow(), getCol());
		Node Target(targetrow, targetcol);
		if (chaseMode() && !isOnPacMan())
		{
			nodes = findPath(map, Inky, Target, &manager);
			if (!nodes.empty())
				translateNodeToDir(nodes[0]);
			moveGhost();
			renderGhost();
		}
		return;

	}

	if ((fmod(pixelX(), 16.0) == 0) && (fmod(pixelY(), 16.0) == 0)) 
	{
		updateRowsorCols();
		nodes.erase(nodes.begin());
		if (!nodes.empty())
			translateNodeToDir(nodes[0]);
		else
			moving = false;
	}
	if (moving) {
		moveGhost();
		renderGhost();
		return;
	}

}