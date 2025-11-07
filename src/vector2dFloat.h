//
// Created by Hassan Hashmi on 2025-11-07.
//

#ifndef CPLUSPONG_VECTOR2DFLOAT_H
#define CPLUSPONG_VECTOR2DFLOAT_H
#include <cmath>
/*
 * Created to port game to pixel based representation in the future
 */
struct Vector2DFloat {
    float x;
    float y;
    explicit Vector2DFloat(const float x = 0.0f, const float y = 0.0f) : x(x), y(y){}

    Vector2DFloat operator - (const Vector2DFloat& other) const {
        return Vector2DFloat(x - other.x, y - other.y);
    }

    Vector2DFloat operator * (float scalar) const {
        return Vector2DFloat(x * scalar, y * scalar);
    }
};

inline float Dot(const Vector2DFloat& a, const Vector2DFloat& b) {
    return a.x * b.x + a.y * b.y;
}

inline Vector2DFloat Normalize(const Vector2DFloat& v) {
    const float magnitude = std::sqrt(v.x * v.x + v.y * v.y);
    return Vector2DFloat(v.x / magnitude, v.y / magnitude);
}

inline Vector2DFloat ReflectAcrossNormal(const Vector2DFloat& v, const Vector2DFloat& normal) {
    const Vector2DFloat n = Normalize(normal);
    return v - n * (2.0f * Dot(v, n));
}
#endif //CPLUSPONG_VECTOR2DFLOAT_H