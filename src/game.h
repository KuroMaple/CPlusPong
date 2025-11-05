#pragma once
#include <string>

class Game {
	// Private Fields
	bool isGameOver;
	int width, height;
	// Private methods
	static void RenderText(int i, int j, std::string symbol);
public:
	// Public fields
	std::string displayMessage;

	// Public Methods
	Game();
	bool GetIsGameOver();
	void SetIsGameOver(bool isGameOver);
	void Render() const;

};
