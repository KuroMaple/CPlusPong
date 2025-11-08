#pragma once
#include <string>

#include "ball.h"
#include "board.h"
#include "paddle.h"

class Game {
public:
	// Fields
	std::string displayMessage;
	Board board;

	// Methods
	Game(int w, int h);
	[[nodiscard]] bool GetIsGameOver() const;
	void SetIsGameOver(bool isGameOver);
	void Render();
	void Update();
	void MovePlayerPaddle(MoveDirection direction);
	static void RenderTitle();
	static void RenderGameOverText();
	static void ClearScreen();
	static void RenderYouLoseText();
private:
	// Fields
	bool isGameOver = false;
	int width, height;
	int ballFrameCounter;
	int ballSpeed;
	int playerScore;
	int CPUScore;
	Ball ball;
	Paddle playerPaddle;
	Paddle cpuPaddle;

	// Methods
	static void RenderText(int i, int j, char symbol);
	void CheckCollisions();
	[[nodiscard]] bool IsPointOver(const Vector2D& ballPos) const;
	[[nodiscard]] bool IsBallHitWall(const Vector2D& ballPos) const;
	std::optional<std::pair<Paddle*, Vector2D>> CheckPaddleHit(const Vector2D& ballPos);
	void MoveCPUPaddle();
	void RenderScore() const;
	void UpdateScore();
};
