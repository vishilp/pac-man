#include "PacMan.h"

PacMan::PacMan(int x, int y)
{
	posx = x;
	posy = y;
}

PacMan::~PacMan()
{

}

bool PacMan::isAlive() { return alive; }