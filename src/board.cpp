//
// Created by Hassan Hashmi on 2025-11-04.
//

#include "board.h"

Board::Board(const int w, const int h): width(w), height(h), boardCells(h) {
    for (int i = 0; i < height; ++i) {
        boardCells[i].reserve(width);
        for (int j = 0; j < width; ++j) {
            if (i == height - 1 || i == 0 || j == width - 1 || j == 0) {
                boardCells[i].emplace_back(Vector2D(j, i), '.');
            } else {
                boardCells[i].emplace_back(Vector2D(j, i));
            }
        }
    }
}

const BoardCell & Board::GetCellDataAt(const Vector2D &pos) const {
    return this->boardCells[pos.y][pos.x];
}

void Board::SetCellDataAt(const Vector2D &pos, const char newSymbol) {
    this->boardCells[pos.y][pos.x].SetSymbol(newSymbol);
}

