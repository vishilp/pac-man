#include "PacMan.h"

PacMan::PacMan(int r, int c)
{
	row = r;
	col = c;
}

void PacMan::movePacMan()
{
	col += 1;
}

PacMan::~PacMan()
{

}

bool PacMan::isAlive() { return alive; }