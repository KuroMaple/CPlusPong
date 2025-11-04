// CPlusPong.cpp : Defines the entry point for the application.
//

#include "game.h"
#include <iostream>
#include "input_handler.h"
#include <chrono>
#include <thread>
#include "input_event.h"
#include  "constants.h"
int main()
{
	setNonCanonicalMode();
	Game game;
	while(!game.GetIsOver()){
		auto lastUpdateTime = std::chrono::steady_clock::now() - std::chrono::milliseconds(FRAME_DURATION);

		do {
			auto currTime = std::chrono::steady_clock::now();
			if (currTime - lastUpdateTime > FRAME_DURATION) {
				game.displayMessage = "Game is Active";
				lastUpdateTime = currTime;
			}


			InputEvent event = getKeyPress();
			switch (event) {
				case InputEvent::KEY_W: {
					std::cout << "W hit!" << '\n';
					break;
				}
				case InputEvent::KEY_S:
					std::cout << "S hit!" << '\n';
					break;
				case InputEvent::ESCAPE:
					game.SetIsOver(true);
					break;
				default:
					break;
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		} while (!game.GetIsOver());
	resetTerminalMode();
	}
	return 0;
}
