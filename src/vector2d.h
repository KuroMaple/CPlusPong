#ifndef CPLUSPONG_VECTOR2D_H
#define CPLUSPONG_VECTOR2D_H
struct Vector2D {
    int x;
    int y;
    explicit Vector2D(const int x = 0, const int y = 0) : x(x), y(y){}
};
#endif //CPLUSPONG_VECTOR2D_H