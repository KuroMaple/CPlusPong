#include "game.h"
#include <iostream>
#include "constants.h"

Game::Game() {
	this->isGameOver = false;
	width = GRID_WIDTH;
	height = GRID_HEIGHT;
}

void Game::RenderText(int i, int j, std::string symbol) {
	std::cout << "\033[" << (i + 1) << ";" << (j + 1) << "H";
	std::cout << symbol;
	std::cout.flush();
}


bool Game::GetIsGameOver() {
	return this->isGameOver;
}

void Game::SetIsGameOver(bool isGameOver) {
	this->isGameOver = isGameOver;
}

void Game::Render() const {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			RenderText(i, j, ".");
		}
	}
}
