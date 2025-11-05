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
	enableRawInput();
	Game game(BOARD_WIDTH, BOARD_HEIGHT);
	while(!game.GetIsGameOver()){
		auto lastUpdateTime = std::chrono::steady_clock::now() - std::chrono::milliseconds(FRAME_DURATION);

		do {
			auto currTime = std::chrono::steady_clock::now();
			if (currTime - lastUpdateTime >= FRAME_DURATION) {

				lastUpdateTime = currTime;
				game.Update();
				game.Render();
			}


			InputEvent event = pollKeyboardInput();
			switch (event) {
				case InputEvent::KEY_W: {
					std::cout << "W hit!" << '\n';
					break;
				}
				case InputEvent::KEY_S:
					std::cout << "S hit!" << '\n';
					break;
				case InputEvent::ESCAPE:
					game.SetIsGameOver(true);
					break;
				default:
					break;
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		} while (!game.GetIsGameOver());
	restoreInputMode();
	}
	return 0;
}
