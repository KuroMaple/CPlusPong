#include "game.h"
#include <iostream>
#include "constants.h"

Game::Game(const int w, const int h)
	:	width(w),
		height(h),
		board(w, h),
		ball(Vector2D(w/2 - 1, h/2 - 1), Vector2D(-1,0), '@'),
		playerPaddle("PlayerPaddle", '|', 1, 3, true, Vector2D(0, h/2 - 1)),
		cpuPaddle("CPUPaddle", '|', 1, 3, false, Vector2D(w - 1, h/2 - 1)) {
	ballSpeed = 3; // increase speed as rally goes on
	ballFrameCounter = 0;
}

void Game::RenderText(int i, int j, char symbol) {
	std::cout << "\033[" << (i + 1) << ";" << (j + 1) << "H";
	std::cout << symbol;
	std::cout.flush();
}

void Game::CheckCollisions() {
	auto ballPos = ball.GetPosition();

	if (IsPointOver(ballPos)) {
		ball.ResetBall();
	}
	if (IsBallHitWall(ballPos)) {
		ball.BounceBall();
	}

	if (const auto hitInfo = CheckPaddleHit(ballPos)) {
		Paddle* paddle = hitInfo->first; // CPU or Player paddle?
		Vector2D hitCell = hitInfo->second;
		ball.ReflectBall(hitCell, paddle->GetCenterPosition());
	}

}

bool Game::IsPointOver(const Vector2D& ballPos) const {
	return ballPos.x < 0 || ballPos.x >= width;
}

bool Game::IsBallHitWall(const Vector2D &ballPos) const {
	return ballPos.y == 0 || ballPos.y == height;
}

std::optional<std::pair<Paddle *, Vector2D>> Game::CheckPaddleHit(const Vector2D &ballPos) {
	if (auto hit = playerPaddle.GetHitCell(ballPos)) {
		return std::pair { &playerPaddle, *hit };
	}

	if (auto hit = cpuPaddle.GetHitCell(ballPos)) {
		return std::pair{ &cpuPaddle, *hit };
	}

	return std::nullopt;
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
			Vector2D ballPos = ball.GetPosition();

			if (ballPos.x == x && ballPos.y == y) {
				RenderText(y, x, ball.GetSymbol());
			} else if (playerPaddle.IsPaddleCell(x, y)) {
				RenderText(y, x, playerPaddle.GetSymbol());
			} else if (cpuPaddle.IsPaddleCell(x, y)) {
				RenderText(y, x, cpuPaddle.GetSymbol());
			}else {
				RenderText(y, x, currCell.GetSymbol());
			}
		}
	}

	std::cout << "\033[?25h"; // Show cursor

	std::cout.flush();
}

void Game::Update() {
	this->ballFrameCounter++;
	if (this->ballFrameCounter >= this->ballSpeed) {
		this->ball.Update();
		CheckCollisions();
		this->ballFrameCounter = 0;
	}

}

void Game::MovePaddle(MoveDirection direction) {
	// Move the paddle only if dimensions allow for it to be moved
	double halfH = playerPaddle.GetHalfHeight() / 2;

	switch (direction) {
		case MoveDirection::UP: {
			if (playerPaddle.GetCenterPosition().y - halfH > 0) {
				playerPaddle.MoveUp();
			}
			break;
		}
		case MoveDirection::DOWN: {
			if (playerPaddle.GetCenterPosition().y + halfH <= height) {
				playerPaddle.MoveDown();
			}
			break;
		}
	}
}
