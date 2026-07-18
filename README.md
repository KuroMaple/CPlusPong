# CPlusPong

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

A low-level **C++ Pong implementation** built from scratch to explore fundamental game programming concepts including game loop architecture, collision detection, 2D physics, and object-oriented design without relying on external game engines.

## Demo

https://github.com/user-attachments/assets/bc5fe25e-f2b5-4731-ab9b-b068d887d292

## Technical Highlights

- Built a custom real-time game loop using modern C++
- Implemented object-oriented game entities and state management
- Developed collision detection and ball reflection physics
- Created vector-based movement and physics calculations
- Built a lightweight terminal rendering system using ANSI escape codes
- Structured the project using CMake for cross-platform build management

## Features

- Smooth paddle and ball movement
- Collision detection with dynamic ball reflection
- Score tracking and game reset logic
- Console-based rendering system

## Development Log

Follow the step-by-step implementation process and technical learnings in the [DEVLOG.md](DEVLOG.md).

## Build Instructions

### Requirements

- C++17 compatible compiler
- CMake 3.16+
- Terminal supporting ANSI escape codes

### Build Steps

Clone the repository:

```bash
git clone https://github.com/KuroMaple/CPlusPong.git
```

Generate build files:

```bash
cmake ..
```

Compile:

```bash
cmake --build .
```

Run:

```bash
./CPlusPong
```
