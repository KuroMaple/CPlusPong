//
// Created by Hassan Hashmi on 2025-11-06.
//

#include "paddle.h"

#include <iostream>

Paddle::Paddle(std::string name, char sym, int w, int h, bool isPlayer, Vector2D startPos)
    :   name(name), symbol(sym), width(w), height(h), isPlayerControlled(isPlayer), centerPosition(startPos)  {
    paddleCells.reserve(width * height);
    UpdatePaddleCells();
}

std::string Paddle::GetName() {
    return this->name;
}

Vector2D Paddle::GetCenterPosition() {
    return this->centerPosition;
}

char Paddle::GetSymbol() {
    return this->symbol;
}

void Paddle::MoveUp() {
    centerPosition.y--;
    UpdatePaddleCells();
}

void Paddle::MoveDown() {
    centerPosition.y++;
    UpdatePaddleCells();
}

void Paddle::UpdatePaddleCells() {
    paddleCells.clear();
    int halfW = width / 2;
    int halfH = height / 2;
    for (int dx = -halfW; dx <= halfW; ++dx) {
        for (int dy = -halfH; dy <= halfH; ++dy) {
            paddleCells.emplace_back(centerPosition.x + dx, centerPosition.y + dy);
        }
    }
}

int Paddle::GetHalfHeight() const {
    return height / 2;
}

bool Paddle::IsPaddleCell(int x, int y) {
    return std::ranges::any_of(paddleCells, [x, y](const Vector2D& pc) {
        return pc.x == x and pc.y == y;
    });
}

std::optional<Vector2D> Paddle::GetHitCell(const Vector2D &ballPos) const {
    for (const auto& pc : paddleCells) {
        if (ballPos.x == pc.x && ballPos.y == pc.y) {
            return pc;
        }
    }
    return std::nullopt;
}


