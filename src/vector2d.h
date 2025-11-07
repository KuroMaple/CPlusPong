#ifndef CPLUSPONG_VECTOR2D_H
#define CPLUSPONG_VECTOR2D_H
struct Vector2D {
    int x;
    int y;

    explicit Vector2D(const int x = 0, const int y = 0) : x(x), y(y) {}

    Vector2D operator - (const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator + (const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator * (const int scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    Vector2D& operator += (const Vector2D& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    bool operator == (const Vector2D& other) const {
        return x == other.x && y == other.y;
    }
};
#endif //CPLUSPONG_VECTOR2D_H