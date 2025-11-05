//
// Created by Hassan Hashmi on 2025-11-05.
//

#ifndef CPLUSPONG_BOARDCELL_H
#define CPLUSPONG_BOARDCELL_H
#include <string>

#include "vector2d.h"


class BoardCell {
public:
    explicit BoardCell(const Vector2D &pos, const char &sym = '.');
    [[nodiscard]] const Vector2D &GetPosition() const ;
    [[nodiscard]] const char &GetSymbol() const;
    void SetSymbol(char newSym);
private:
    Vector2D position;
    char symbol;
};


#endif //CPLUSPONG_BOARDCELL_H