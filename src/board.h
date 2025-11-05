//
// Created by Hassan Hashmi on 2025-11-04.
//

#ifndef CPLUSPONG_BOARD_H
#define CPLUSPONG_BOARD_H
#include <vector>
#include "board_cell.h"


class Board {
public:
    Board(int w, int h);
    [[nodiscard]] const BoardCell &GetCellDataAt(const Vector2D &pos) const;
    void SetCellDataAt(const Vector2D &pos, char newSymbol);

private:
    int width, height;
    std::vector<std::vector<BoardCell>> boardCells;

};


#endif //CPLUSPONG_BOARD_H