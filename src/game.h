#pragma once
#include <string>

class Game {
// Fields
private:
	bool isOver;
	int width, height;
public:
	std::string displayMessage;

// Methods
	Game();
	bool GetIsOver();
	void SetIsOver(bool isOver);
	void Render() const;

};
