#include "Clyde.h"

void Clyde::renderGhost()
{
	SDL_Rect location = { pixelX(), pixelY(), TextureManager::SpriteWidth, TextureManager::SpriteHeight };
	SDL_RenderCopy(ren, sprites, TextureManager::ReturnClydeRect(), &location);
}

void Clyde::shyModeMove()
{
	std::pair<int, int> homeZone[] = { //row, col
		{29,1}, {29,2}, {29,3}, {29,4}, {29,5}, {29,6}, {29,7}, {29,8}, {29,9}, {29,10}, {29,11}, {29, 12},
		{28,12}, {27,12}, {26, 12}, {26, 11}, {26, 10}, {26, 9}, {25, 9}, {24, 9}, {23,9}, {23,8}, {23,7}, {23,6},
		{24,6}, {25, 6}, {26, 6}, {26, 5}, {26, 4}, {26, 3}, {26, 2}, {26,1}, {27, 1}, {28, 1}
	};
};


void Clyde::updateGhost()
{
	if (isOnPacMan())
		return;
	//finish direction before running A* again
	if ((fmod(pixelX(), 16.0) == 0) && (fmod(pixelY(), 16.0) == 0)) ///only change direction when completely on a cell
	{
		updateRowsorCols();
		moving = false;
	}
	if (moving) {
		moveGhost();
		renderGhost();
	}
	else
	{
		moving = true;
		NodeManager manager;
		Node Pinky(getRow(), getCol());
		Node Pac(player->Row(), player->Col());

		if (chaseMode() && !isOnPacMan())
		{
			std::vector<Node> nodes = findPath(map, Pinky, Pac, &manager);
			if (nodes.size() >= 8)
			{
				setChaseMode(false);
				return;
			}
			if (!nodes.empty())
				translateNodeToDir(nodes[0]);
			moveGhost();
			renderGhost();
			if ((fmod(pixelX(), 16.0) == 0) && (fmod(pixelY(), 16.0) == 0)) ///only change direction when completely on a cell
			{
				updateRowsorCols();
				moving = false;
			}
		}
		else if (!chaseMode && !isOnPacMan())
		{
			shyModeMove();
		}
	}

}