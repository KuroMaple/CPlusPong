#pragma once
#include <cstddef>
#include <chrono>

static constexpr size_t FRAMERATE = 60;
static constexpr std::chrono::milliseconds FRAME_DURATION(1000u / FRAMERATE);