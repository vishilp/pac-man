#include "Blinky.h"

void Blinky::renderGhost()
{
	SDL_Rect location = { pixelX(), pixelY(), TextureManager::SpriteWidth, TextureManager::SpriteHeight };
	SDL_RenderCopy(ren, sprites, TextureManager::ReturnBlinkyRect(), &location);
}

void Blinky::updateGhost()
{
	if (isOnPacMan())
		return;
	NodeManager manager;
	Node Blinky(getRow(), getCol());
	Node Pac(player->Row(), player->Col());
	if (chaseMode())
	{
		std::vector<Node> nodes = findPath(map, Blinky, Pac, &manager);
		translateNodeToDir(nodes[0]);
		setRow(nodes[0].row);
		setCol(nodes[0].col);
	}
}

void Blinky::translateNodeToDir(Node node)
{
	int r = getRow();
	int c = getCol();

	if (node.row == r)  //if rows are same, clearly the ghost needs to move through cols
	{
		if (node.col == c + 1) {
			setDirection(RIGHT);
			return;
		}
		if (node.col == c - 1) {
			setDirection(LEFT);
			return;
		}
		
	}

	else
	{
		if (node.row == r + 1) {
			setDirection(DOWN);
			return;
		}
		if (node.row == r - 1) {
			setDirection(UP);
			return;
		}
	}
}