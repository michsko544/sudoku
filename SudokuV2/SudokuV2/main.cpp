#include <iostream>
#include "Board.h"


int main()
{

	Board game;
	game.setData(0, 0, 5);
	game.setData(0, 2, 4);
	game.setData(1, 0, 3);
	game.setData(2, 0, 1);
	game.setData(2, 2, 8);
	game.setData(0, 3, 8);
	game.setData(0, 4, 1);
	game.setData(0, 5, 7);
	game.setData(1, 3, 4);
	game.setData(1, 4, 5);
	game.setData(2, 3, 6);
	game.setData(2, 4, 2);
	game.setData(1, 7, 8);
	game.setData(2, 7, 7);
	game.setData(4, 1, 6);
	game.setData(5, 2, 5);
	game.setData(3, 4, 2);
	game.setData(4, 3, 5);
	game.setData(4, 5, 7);
	game.setData(5, 4, 8);
	game.setData(3, 6, 7);
	game.setData(4, 7, 9);
	game.setData(6, 1, 4);
	game.setData(7, 1, 3);
	game.setData(6, 4, 8);
	game.setData(6, 5, 9);
	game.setData(7, 4, 1);
	game.setData(7, 5, 5);
	game.setData(8, 3, 3);
	game.setData(8, 4, 4);
	game.setData(8, 5, 7);
	game.setData(6, 6, 1);
	game.setData(6, 8, 3);
	game.setData(7, 8, 4);
	game.setData(8, 6, 8);
	game.setData(8, 8, 6);

	game.Show();

	bool changes = true;
	while (changes)
	{
		changes = false;
		
		changes |= game.subsquareRefresh();
		changes |= game.horizontalRefresh();
		changes |= game.verticalRefresh();
		changes |= game.setValues();
	}
	
	std::cout << "\n\n";
	game.Show();



	return 111;
}