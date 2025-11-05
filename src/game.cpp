#include "game.h"
#include <iostream>
#include "constants.h"

Game::Game() {
	this->isOver = false;
	width = GRID_WIDTH;
	height = GRID_HEIGHT;
}

bool Game::GetIsOver() {
	return this->isOver;
}

void Game::SetIsOver(bool isOver) {
	this->isOver = isOver;
}

void Game::Render() const {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			std::cout << "\033[" << (i + 1) << ";" << (j + 1) << "H"; // Setting the cursor
			std::cout << "*";
			std::cout.flush();
		}
	}
}
