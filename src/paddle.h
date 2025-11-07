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
    [[nodiscard]] double GetHalfHeight() const;
    bool IsPaddleCell(int x, int y);
    [[nodiscard]] std::optional<Vector2D> GetHitCell(const Vector2D &ballPos) const;
private:
    std::string name;
    char symbol;
    int width;
    int height;
    bool isPlayerControlled;
    Vector2D centerPosition;
    std::vector<Vector2D> paddleCells;
};


#endif //CPLUSPONG_PADDLE_H