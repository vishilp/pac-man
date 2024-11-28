#include "Clyde.h"

void Clyde::renderGhost()
{
	SDL_Rect location = { pixelX(), pixelY(), TextureManager::SpriteWidth, TextureManager::SpriteHeight };
	SDL_RenderCopy(ren, sprites, TextureManager::ReturnClydeRect(), &location);
}

void Clyde::shyModeMove()
{
	srand(time(0));
	int randomNum = rand() % 34; //number between 0 and 33
	std::pair<int,int> pair = homeZone[randomNum];
	NodeManager manager;
	Node Clyde(getRow(), getCol());
	Node Target(pair.first, pair.second);
	std::vector<Node> nodes = findPath(map, Clyde, Target, &manager);
	if (!nodes.empty())
		translateNodeToDir(nodes[0]);
	moveGhost();
	renderGhost();

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
			if (nodes.size() <= 8)
			{
				shyModeMove();
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