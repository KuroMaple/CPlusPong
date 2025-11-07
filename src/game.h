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
	void MovePaddle(MoveDirection direction);

private:
	// Fields
	bool isGameOver = false;
	int width, height;
	Ball ball;
	Paddle playerPaddle;
	Paddle cpuPaddle;
	// Methods
	static void RenderText(int i, int j, char symbol);
	void CheckCollisions();
	[[nodiscard]] bool IsPointOver(const Vector2D& ballPos) const;
	[[nodiscard]] bool IsBallHitWall(const Vector2D& ballPos) const;

};
