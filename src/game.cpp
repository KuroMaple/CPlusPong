#include "game.h"
#include <iostream>
#include "constants.h"

Game::Game(const int w, const int h)
	: width(w),
      height(h),
	  board(w, h),
	  ball(Vector2D(w/2 - 1, h/2 - 1), Vector2D(-1,0), '@') {
}

void Game::RenderText(int i, int j, char symbol) {
	std::cout << "\033[" << (i + 1) << ";" << (j + 1) << "H";
	std::cout << symbol;
	std::cout.flush();
}


bool Game::GetIsGameOver() const {
	return this->isGameOver;
}

void Game::SetIsGameOver(bool isGameOver) {
	this->isGameOver = isGameOver;
}

void Game::Render() {
	std::cout << "\033[?25l"; // Hide cursor

	// Draw main board
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			BoardCell currCell = board.GetCellDataAt(Vector2D(j, i));
			RenderText(i, j, currCell.GetSymbol());
		}
	}

	// Overlay ball
	board.SetCellDataAt(ball.GetPosition(), ball.GetSymbol());

	std::cout << "\033[?25h"; // Show cursor
}

void Game::Update() {
	this->ball.Update();
}
