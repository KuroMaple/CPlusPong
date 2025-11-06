#include "game.h"
#include <iostream>
#include "constants.h"

Game::Game(const int w, const int h)
	: width(w),
      height(h),
	  board(w, h),
	  ball(Vector2D(w/2 - 1, h/2 - 1), Vector2D(-1,-1), '@') {
}

void Game::RenderText(int i, int j, char symbol) {
	std::cout << "\033[" << (i + 1) << ";" << (j + 1) << "H";
	std::cout << symbol;
	std::cout.flush();
}

void Game::CheckCollisions() {
	auto currBallPos = ball.GetPosition();
	// Map boundary check
	if (currBallPos.x == 0 || currBallPos.x == width || currBallPos.y == 0 || currBallPos.y == height) {
		ball.ReflectBall();
	}
}


bool Game::GetIsGameOver() const {
	return this->isGameOver;
}

void Game::SetIsGameOver(bool isGameOver) {
	this->isGameOver = isGameOver;
}

void Game::Render() {
	std::cout << "\033[?25l"; // Hide cursor

	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			BoardCell currCell = board.GetCellDataAt(Vector2D(x, y));
			if (ball.GetPosition().x == x && ball.GetPosition().y == y) {
				RenderText(y, x, ball.GetSymbol());
			} else {
				RenderText(y, x, currCell.GetSymbol());
			}
		}
	}

	std::cout << "\033[?25h"; // Show cursor

	std::cout.flush();
}

void Game::Update() {
	this->ball.Update();
	CheckCollisions();
}
