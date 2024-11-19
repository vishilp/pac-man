#pragma once
#include "globals.h"

class Ghost {
	public:
		Ghost(int r, int c);
		bool isAlive();
		int getRow(); //in the array, NOT in pixels
		int getCol();
		void setRow(int r);
		void setCol(int c);
		void updateRowsorCols(int dir);
		int pixelX() { return pixelx; }
		int pixelY() { return pixely; }
	private:
		bool alive = true;
		int row;
		int col;
		float pixelx;
		float pixely;
		int direction;

};
