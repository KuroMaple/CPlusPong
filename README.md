# CPlusPong 
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white) 

A C++ practice project where I built the classic game **Pong** from scratch. This project highlights my understanding of **object-oriented programming, game loop design, collision detection, and basic physics implementation** in pure raw C++.

**Features:**
- Paddle and ball mechanics with smooth movement
- Collision detection and ball reflection
- Score tracking and game reset logic
- Console-based rendering using 2D vectors

## Demo


https://github.com/user-attachments/assets/bc5fe25e-f2b5-4731-ab9b-b068d887d292



## Development Log
Follow my step-by-step development progress and learnings in the [DEVLOG.md](DEVLOG.md).

## Build and Run Instructions ( Mac Only Sorry Windows ;-; )
### Requirements
- A C++17 (or newer) compatible compiler e.g., g++, clang++, or MSVC
- CMake (version 3.16 or higher)
- A terminal that supports ANSI escape codes (for smooth rendering) sized to at least 200x200

### Build Steps
1. Clone the repository
   ```
   git clone https://github.com/KuroMaple/CPlusPong.git
   ```
2. Generate build files with CMake
   
    ```
    cmake ..
    ```
3. Compile the project. This will produce an executable named `CPlusPong`
    ```
    cmake --build .
    ```
    
4. Run `CPlusPong` in a large enough terminal window via:
    ```
    ./CPlusPong
    ```
