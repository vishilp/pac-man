#include "PacMan.h"

PacMan::PacMan(int x, int y)
{
	posx = x;
	posy = y;
}

void PacMan::movePacMan()
{
	posx += 1;
}

PacMan::~PacMan()
{

}

bool PacMan::isAlive() { return alive; }