#pragma once
#include <cstddef>
#include <chrono>

static constexpr size_t FRAMERATE = 60;
static constexpr std::chrono::milliseconds FRAME_DURATION(1000u / FRAMERATE);
static constexpr size_t GRID_WIDTH = 50;
static constexpr size_t GRID_HEIGHT = 30;