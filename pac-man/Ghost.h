#pragma once
#include "globals.h"

class Ghost {
	public:
		bool isAlive();
		int getRow(); //in the array, NOT in pixels
		int getCol();
		void setRow(int r);
		void setCol(int c);
		void updateRowsorCols(int dir);
	private:
		bool alive = true;
		int row;
		int col;

};
