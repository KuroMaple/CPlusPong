//
// Created by Hassan Hashmi on 2025-11-05.
//

#include "ball.h"

#include "constants.h"

// Vector2D Ball::StartPos() {
//     return Vector2D(BOARD_WIDTH / 2 - 1, BOARD_HEIGHT / 2 - 1);
// }

Ball::Ball(const Vector2D &startPos, const Vector2D &startVel, const char symbol)
    :   position(startPos),
        velocity(startVel),
        symbol(symbol){}

void Ball::Update() {
    position.x += velocity.x;
    position.y += velocity.y;
}

void Ball::ReflectBall() {
    this->velocity.x *= -1;
    this->velocity.y *= -1;
}

Vector2D Ball::GetPosition() const {
    return this->position;
}

char Ball::GetSymbol() const {
    return this->symbol;
}

