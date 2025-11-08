#include "game.h"
#include <iostream>
#include <thread>

#include "constants.h"

Game::Game(const int w, const int h)
	:	width(w),
		height(h),
		board(w, h),
		ball(Vector2D(w/2 - 1, h/2 - 1), Vector2D(1,0), '@'),
		playerPaddle("PlayerPaddle", '|', 1, 3, true, Vector2D(0, h/2 - 1)),
		cpuPaddle("CPUPaddle", '|', 1, 3, false, Vector2D(w - 1, h/2 - 1)) {
	ballSpeed = 3; // increase speed as rally goes on
	ballFrameCounter = 0;
	playerScore = 0;
	CPUScore = 0;
}

void Game::RenderText(const int i, const int j, const char symbol) {
	std::cout << "\033[" << (i + 1) << ";" << (j + 1) << "H";
	std::cout << symbol;
	std::cout.flush();
}

void Game::CheckCollisions() {
	auto ballPos = ball.GetPosition();

	if (IsPointOver(ballPos)) {
		// Update score before reset
		UpdateScore();
		ball.ResetBall();
		ballSpeed = 3;
	}
	if (IsBallHitWall(ballPos)) {
		ball.BounceBall();
	}

	if (const auto hitInfo = CheckPaddleHit(ballPos)) {
		Paddle* paddle = hitInfo->first; // CPU or Player paddle?
		Vector2D hitCell = hitInfo->second;
		ball.ReflectBall(hitCell, paddle->GetCenterPosition());
		ballSpeed--;
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

void Game::MoveCPUPaddle() {
	Vector2D ballPos = ball.GetPosition();
	Vector2D ballVel = ball.GetVelocity();
	Vector2D paddleCenter = cpuPaddle.GetCenterPosition();

	// Only moving if ball is moving towards CPU
	if (ballVel.x < 0) {
		return;
	}

	// Impossible mode
	if (ballPos.y < paddleCenter.y) {
		cpuPaddle.MoveUp();
	} else if (ballPos.y > paddleCenter.y) {
		cpuPaddle.MoveDown();
	}



}

void Game::RenderScore() const {
	std::cout << "\033[?25l"; // Hide cursor

	int scoreStartCol = width + 5;
	int playerRow = 5;
	int cpuRow = playerRow + 2;

	std::cout << "\033[" << playerRow << ";" << scoreStartCol << "H";
	std::cout << "Player: " << playerScore;

	std::cout << "\033[" << cpuRow << ";" << scoreStartCol << "H";
	std::cout << "CPU: " << CPUScore;
	std::cout.flush();

	std::cout << "\033[?25h"; // Show cursor
}

void Game::UpdateScore() {
	Vector2D ballPos = ball.GetPosition();
	if (ballPos.x < 0) {
		CPUScore++;
	} else if (ballPos.x >= width) {
		playerScore++;
	}

	if (playerScore == 3 || CPUScore == 3) {
		SetIsGameOver(true);
	}
}


bool Game::GetIsGameOver() const {
	return isGameOver;
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

	RenderScore();

	std::cout.flush();
}

void Game::Update() {
	ballFrameCounter++;

	if (ballFrameCounter >= ballSpeed) {
		ball.Update();
		CheckCollisions();
		ballFrameCounter = 0;
	}
	MoveCPUPaddle();
}

void Game::MovePlayerPaddle(const MoveDirection direction) {

	if (direction == playerPaddle.GetLastMoveDirection()) {
		playerPaddle.IncrementMoveMomentum();
	} else {
		playerPaddle.ResetMoveMomentum();
	}

	playerPaddle.SetLastMoveDirection(direction);

	const int steps = playerPaddle.GetMoveMoveMomentum();
	switch (direction) {
		case MoveDirection::UP: {
			for (int i = 0; i < steps; ++i) {
				if (playerPaddle.GetCenterPosition().y - playerPaddle.GetHalfHeight() > 0) {
					playerPaddle.MoveUp();
				}
			}
			break;
		}
		case MoveDirection::DOWN: {
			for (int i = 0; i < steps; ++i) {
				if (playerPaddle.GetCenterPosition().y + playerPaddle.GetHalfHeight() < height - 1) {
					playerPaddle.MoveDown();
				}
			}
			break;
		}
	}
}

void Game::RenderTitle() {
	std::cout << R"(
    ▄▄▄▄   ▄▄▄▄▄▄    ▄▄▄▄                          ▄▄▄▄▄▄
  ██▀▀▀▀█  ██▀▀▀▀█▄  ▀▀██                          ██▀▀▀▀█▄
 ██▀       ██    ██    ██      ██    ██  ▄▄█████▄  ██    ██   ▄████▄   ██▄████▄   ▄███▄██
 ██        ██████▀     ██      ██    ██  ██▄▄▄▄ ▀  ██████▀   ██▀  ▀██  ██▀   ██  ██▀  ▀██
 ██▄       ██          ██      ██    ██   ▀▀▀▀██▄  ██        ██    ██  ██    ██  ██    ██
  ██▄▄▄▄█  ██          ██▄▄▄   ██▄▄▄███  █▄▄▄▄▄██  ██        ▀██▄▄██▀  ██    ██  ▀██▄▄███
    ▀▀▀▀   ▀▀           ▀▀▀▀    ▀▀▀▀ ▀▀   ▀▀▀▀▀▀   ▀▀          ▀▀▀▀    ▀▀    ▀▀   ▄▀▀▀ ██
                                                                                  ▀████▀▀
)" << '\n';
	std::this_thread::sleep_for(std::chrono::seconds(2));
}

void Game::RenderGameOverText() {
	std::cout << R"(
    ▄▄▄▄                                             ▄▄▄▄
  ██▀▀▀▀█                                           ██▀▀██
 ██         ▄█████▄  ████▄██▄   ▄████▄             ██    ██  ██▄  ▄██   ▄████▄    ██▄████
 ██  ▄▄▄▄   ▀ ▄▄▄██  ██ ██ ██  ██▄▄▄▄██            ██    ██   ██  ██   ██▄▄▄▄██   ██▀
 ██  ▀▀██  ▄██▀▀▀██  ██ ██ ██  ██▀▀▀▀▀▀            ██    ██   ▀█▄▄█▀   ██▀▀▀▀▀▀   ██
  ██▄▄▄██  ██▄▄▄███  ██ ██ ██  ▀██▄▄▄▄█             ██▄▄██     ████    ▀██▄▄▄▄█   ██
    ▀▀▀▀    ▀▀▀▀ ▀▀  ▀▀ ▀▀ ▀▀    ▀▀▀▀▀               ▀▀▀▀       ▀▀       ▀▀▀▀▀    ▀▀


)" << '\n';
	std::this_thread::sleep_for(std::chrono::seconds(2));
}

void Game::ClearScreen() {
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
}

void Game::RenderYouLoseText() {
	std::cout << R"(
▄▄▄    ▄▄▄                               ▄▄
 ██▄  ▄██                                ██
  ██▄▄██    ▄████▄   ██    ██            ██         ▄████▄   ▄▄█████▄   ▄████▄
   ▀██▀    ██▀  ▀██  ██    ██            ██        ██▀  ▀██  ██▄▄▄▄ ▀  ██▄▄▄▄██
    ██     ██    ██  ██    ██            ██        ██    ██   ▀▀▀▀██▄  ██▀▀▀▀▀▀
    ██     ▀██▄▄██▀  ██▄▄▄███            ██▄▄▄▄▄▄  ▀██▄▄██▀  █▄▄▄▄▄██  ▀██▄▄▄▄█     ██        ██        ██
    ▀▀       ▀▀▀▀     ▀▀▀▀ ▀▀            ▀▀▀▀▀▀▀▀    ▀▀▀▀     ▀▀▀▀▀▀     ▀▀▀▀▀      ▀▀        ▀▀        ▀▀
)" << '\n';
	std::this_thread::sleep_for(std::chrono::seconds(2));
}


