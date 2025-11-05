//
// Created by Hassan Hashmi on 2025-11-05.
//

#include "board_cell.h"
BoardCell::BoardCell(const Vector2D &pos, const char &sym)
    : position(pos), symbol(sym){}

const Vector2D &BoardCell::GetPosition() const {
    return this->position;
}

const char &BoardCell::GetSymbol() const {
    return this->symbol;
}

void BoardCell::SetSymbol(const char newSym) {
    this->symbol = newSym;
}



