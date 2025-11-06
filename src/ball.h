//
// Created by Hassan Hashmi on 2025-11-05.
//

#ifndef CPLUSPONG_BALL_H
#define CPLUSPONG_BALL_H
#include "vector2d.h"

class Ball {
public:
    explicit Ball(const Vector2D &startPos, const Vector2D &startVel, char symbol = '@');
    Vector2D GetPosition() const;
    char GetSymbol() const;
    void Update();
    void ReflectBall();

private:
    Vector2D position;
    Vector2D velocity;
    char symbol;
};


#endif //CPLUSPONG_BALL_H