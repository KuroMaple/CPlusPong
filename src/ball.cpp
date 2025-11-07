//
// Created by Hassan Hashmi on 2025-11-05.
//

#include "ball.h"

#include <iostream>

#include "constants.h"

// Vector2D Ball::StartPos() {
//     return Vector2D(BOARD_WIDTH / 2 - 1, BOARD_HEIGHT / 2 - 1);
// }

Ball::Ball(const Vector2D &startPos, const Vector2D &startVel, const char symbol)
    :   position(startPos),
        velocity(startVel),
        symbol(symbol),
        spawnPosition(startPos){}

void Ball::Update() {
    this->position += this->velocity;
}

void Ball::ReflectBall(const std::optional<Vector2D>& hitCell, const Vector2D &paddleCenter) {
    if (const int offset = hitCell->y - paddleCenter.y; offset < 0) {
        this->velocity.y = -1;
    } else if (offset > 0) {
        this->velocity.y = 1;
    } else {
        this->velocity.y = 0;
    }

    this->velocity.x *= -1;
}


void Ball::BounceBall() {
    this->velocity.y *= -1;
}

void Ball::ResetBall() {
    this->position = spawnPosition;
    this->velocity = Vector2D(-1, 0);
}

Vector2D Ball::GetPosition() const {
    return this->position;
}

Vector2D Ball::GetVelocity() const {
    return  this->velocity;
}

char Ball::GetSymbol() const {
    return this->symbol;
}

