#include "Clyde.h"

void Clyde::renderGhost()
{
	SDL_Rect location = { pixelX(), pixelY(), TextureManager::SpriteWidth, TextureManager::SpriteHeight };
	SDL_RenderCopy(ren, sprites, TextureManager::ReturnClydeRect(), &location);
}

void Clyde::shyModeMove()
{
	if (!shymode) { //if he wasn't already in shymode, i.e. just started going to his homezone
		srand(time(0));
		int randomNum = rand() % 34; //number between 0 and 33
		std::pair<int, int> pair = homeZone[randomNum];
		NodeManager manager;
		Node Clyde(getRow(), getCol());
		Node Target(pair.first, pair.second);
		nodes = findPath(map, Clyde, Target, &manager);

	}
	else
	{
		//go to homezone tile before resetting
		if ((fmod(pixelX(), 16.0) == 0) && (fmod(pixelY(), 16.0) == 0))
		{
			updateRowsorCols();
			if (nodes.empty())
			{
				shymode = false;
			}
			else
			{
				translateNodeToDir(nodes[0]);
				nodes.erase(nodes.begin());
				moveGhost();
				renderGhost();
			}
		}
		else
		{
			moveGhost();
			renderGhost();
		}

	}
	
	
};


void Clyde::updateGhost()
{
	if (map->dotCount > 150)
		return;

	if (isOnPacMan())
	{
		player->setDead();
		return;
	}

	
	if (shymode)
	{
		shyModeMove();
		return;
	}
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
			if (nodes.size() <= 8)
			{
				shyModeMove();
				shymode = true;
				return;
			}
			else {
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
		}
	}

}