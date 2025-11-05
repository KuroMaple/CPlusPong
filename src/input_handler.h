#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
#include <iostream>

#include "input_event.h"

// Enables raw input mode: disables canonical mode and echoing
void enableRawInput() {
    termios settings{};
    if (tcgetattr(STDIN_FILENO, &settings) == -1)
        return;

    settings.c_lflag &= ~(ICANON | ECHO);  // Turn off line buffering and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &settings);
}

// Restores terminal to normal (canonical) mode
void restoreInputMode() {
    termios settings{};
    if (tcgetattr(STDIN_FILENO, &settings) == -1)
        return;

    settings.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &settings);
}

// Checks if a key was pressed and returns the corresponding InputEvent
InputEvent pollKeyboardInput() {
    fd_set inputSet;
    FD_ZERO(&inputSet);
    FD_SET(STDIN_FILENO, &inputSet);

    timeval waitTime{};
    waitTime.tv_sec = 0;
    waitTime.tv_usec = 10000;  // 10 ms polling interval

    int ready = select(STDIN_FILENO + 1, &inputSet, nullptr, nullptr, &waitTime);

    if (ready > 0 && FD_ISSET(STDIN_FILENO, &inputSet)) {
        char key = 0;
        if (read(STDIN_FILENO, &key, 1) == 1) {
            switch (key) {
                case 27: return InputEvent::ESCAPE;
                case 'w': case 'W': return InputEvent::KEY_W;
                case 's': case 'S': return InputEvent::KEY_S;
                default: break;
            }
        }
    }

    return InputEvent::NONE;
}

// Moves the terminal cursor far to the bottom right (to avoid overwriting UI)
void moveCursorToBottomRight() {
    std::cout << "\033[999;999H" << std::flush;
}
