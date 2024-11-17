#include "PacMan.h"

PacMan::PacMan(int r, int c)
{
	row = r;
	col = c;
	pixelx = col * 16;
	pixely = row * 16;
}

void PacMan::movePacMan(int dir)
{
	pixelx++;
}

PacMan::~PacMan()
{

}

bool PacMan::isAlive() { return alive; }