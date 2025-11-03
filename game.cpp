#include "game.h"

Game::Game() {
	this->isOver = false;
}

bool Game::GetIsOver() {
	return this->isOver;
}

void Game::SetIsOver(bool isOver) {
	this->isOver = isOver;
}

