#ifndef __VECTOR_2D_H__
#define __VECTOR_2D_H__

#include <cmath>
#include <ostream>

struct v2d
{
    double x = 0.0;
    double y = 0.0;
    v2d() : x(0), y(0) {}
    v2d(double x, double y) : x(x), y(y) {}
    double length();
    double distance(const v2d & vec);
    double angle();
    v2d unit_vec_to(const v2d & vec);
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

std::ostream & operator<<(std::ostream & os, const v2d & v);
#endif /* __VECTOR_2D_H__ */