//
// Created by Hassan Hashmi on 2025-11-06.
//

#ifndef CPLUSPONG_PADDLE_H
#define CPLUSPONG_PADDLE_H
#include <string>
#include "vector2d.h"
#include <vector>

enum class MoveDirection{
    UP,
    DOWN,
    NONE,
};
class Paddle {
public:
    Paddle(std::string name, char sym, int w, int h, bool isPlayer, Vector2D startPos);
    std::string GetName();
    Vector2D GetCenterPosition();
    char GetSymbol();
    void MoveUp();
    void MoveDown();
    void UpdatePaddleCells();
    [[nodiscard]] int GetHalfHeight() const;
    bool IsPaddleCell(int x, int y);
    [[nodiscard]] std::optional<Vector2D> GetHitCell(const Vector2D &ballPos) const;
    [[nodiscard]] MoveDirection GetLastMoveDirection() const;
    void SetLastMoveDirection(MoveDirection direction);
    void IncrementMoveMomentum();
    void ResetMoveMomentum();
    [[nodiscard]] int GetMoveMoveMomentum() const;
private:
    std::string name;
    char symbol;
    int width;
    int height;
    int moveMomentum;
    int baseSpeed = 1;
    int maxSpeed = 2;
    bool isPlayerControlled;
    Vector2D centerPosition;
    std::vector<Vector2D> paddleCells;
    MoveDirection lastMoveDirection;
};


#endif //CPLUSPONG_PADDLE_H