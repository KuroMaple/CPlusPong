#pragma once
#include <string>

class Game {
// Fields
private:
	bool isOver;
public:
	std::string displayMessage;
// Methods
public:
	Game();

	bool GetIsOver();
	void SetIsOver(bool isOver);

};
