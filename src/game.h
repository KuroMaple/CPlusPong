#pragma once
#include <string>

#include "ball.h"
#include "board.h"

class Game {
public:
	// Public fields
	std::string displayMessage;
	Board board;

	// Public Methods
	Game(int w, int h);
	[[nodiscard]] bool GetIsGameOver() const;
	void SetIsGameOver(bool isGameOver);
	void Render();
	void Update();

private:
	// Private Fields
	bool isGameOver = false;
	int width, height;
	Ball ball;

	// Private methods
	static void RenderText(int i, int j, char symbol);
};
