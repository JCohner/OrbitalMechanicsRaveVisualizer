#ifndef __VECTOR_2D_H__
#define __VECTOR_2D_H__
#include <math.h>

struct Vector2D
{
    double x = 0.0;
    double y = 0.0;
    Vector2D() : x(0), y(0) {}
    Vector2D(double x, double y) : x(x), y(y) {}
    double length();
    double distance(const Vector2D & vec);
    double angle();
};

Vector2D operator+(Vector2D lhs, const Vector2D & rhs);
Vector2D& operator+=(Vector2D& lhs, const Vector2D & rhs);
Vector2D operator-(Vector2D lhs, const Vector2D & rhs);
Vector2D& operator-=(Vector2D& lhs, const Vector2D & rhs);

Vector2D operator*(double lhs, const Vector2D & rhs);
Vector2D& operator*=(double lhs, const Vector2D & rhs);
Vector2D operator*(Vector2D lhs, double rhs);
Vector2D& operator*=(Vector2D& lhs, double rhs);

bool operator==(const Vector2D & lhs, const Vector2D & rhs);

#endif /* __VECTOR_2D_H__ */