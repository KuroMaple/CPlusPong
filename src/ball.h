//
// Created by Hassan Hashmi on 2025-11-05.
//

#ifndef CPLUSPONG_BALL_H
#define CPLUSPONG_BALL_H
#include <optional>

#include "vector2d.h"

class Ball {
public:
    explicit Ball(const Vector2D &startPos, const Vector2D &startVel, char symbol = '@');
    [[nodiscard]] Vector2D GetPosition() const;
    char GetSymbol() const;
    void Update();
    void ReflectBall(const std::optional<Vector2D>& hitCell, const Vector2D &paddleCenter);
    void BounceBall();
    void ResetBall();
private:
    Vector2D spawnPosition;
    Vector2D position;
    Vector2D velocity;
    char symbol;
};


#endif //CPLUSPONG_BALL_H