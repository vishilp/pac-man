#pragma once

//board is an array because no need for dynamic reallocation
class Board {
	public:
		Board() {};
		char board1[1][28] = { //40 rows, 28 col
			{'r', '#', '#', '#', '#', '#', '#', '#', '#','#', '#', '#', '#','#', '#', '#', '#','#', '#', '#', '#','#', '#', '#', '#','#', '#', 'n'}
		};
		int width = 28;
		int height = 40;
};
