#ifndef __VECTOR_2D_H__
#define __VECTOR_2D_H__

#include <cmath>

struct v2d
{
    double x = 0.0;
    double y = 0.0;
    v2d() : x(0), y(0) {}
    v2d(double x, double y) : x(x), y(y) {}
    double length();
    double distance(const v2d & vec);
    double angle();
};

v2d operator+(v2d lhs, const v2d & rhs);
v2d& operator+=(v2d& lhs, const v2d & rhs);
v2d operator-(v2d lhs, const v2d & rhs);
v2d& operator-=(v2d& lhs, const v2d & rhs);

v2d operator*(double lhs, const v2d & rhs);
v2d& operator*=(double lhs, const v2d & rhs);
v2d operator*(v2d lhs, double rhs);
v2d& operator*=(v2d& lhs, double rhs);

bool operator==(const v2d & lhs, const v2d & rhs);

#endif /* __VECTOR_2D_H__ */