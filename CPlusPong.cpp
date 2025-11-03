// CPlusPong.cpp : Defines the entry point for the application.
//

#include "CPlusPong.h"
#include "game.h"
#include <conio.h>

int main()
{
	Game game;
	while(!game.GetIsOver()){
		std::cout << "Game is Active" << std::endl;
		auto event = _kbhit();
		if (event) {
			std::cout << "Key hit!" << std::endl;
			std::cout << "Game terminated!" << std::endl;

			game.SetIsOver(true);
		}
	}
	return 0;
}
