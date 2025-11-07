#ifndef CPLUSPONG_VECTOR2D_H
#define CPLUSPONG_VECTOR2D_H
struct Vector2D {
    float x;
    float y;
    explicit Vector2D(const float x = 0.0f, const float y = 0.0f) : x(x), y(y){}

    Vector2D operator - (const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator * (float scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }
};

inline float Dot(const Vector2D& a, const Vector2D& b) {
    return a.x * b.x + a.y * b.y;
}

inline Vector2D Normalize(const Vector2D& v) {
    const float magnitude = std::sqrt(v.x * v.x + v.y * v.y);
    return Vector2D(v.x / magnitude, v.y / magnitude);
}

inline Vector2D ReflectAcrossNormal(const Vector2D& v, const Vector2D& normal) {
    const Vector2D n = Normalize(normal);
    return v - n * (2.0f * Dot(v, n));
}
#endif //CPLUSPONG_VECTOR2D_H