/**
 * Description: Handles vector/point operations in the cartesian plane. Works for any type. Ints may cause errors with integer division.
 */

#pragma once

const ld eps = 1e-9; //tolerance based on problem
const ld inf = 1e18;

template<class T> struct pnt {
    T x, y;
    pnt(T _x = 0, T _y = 0): x(_x), y(_y) {}
    bool operator<(pnt o) const { return tie(x, y) < tie(o.x, o.y); }
    pnt operator+(pnt o) { return pnt(x + o.x, y + o.y); }
    bool operator==(pnt o) const { return abs(x-o.x) < eps && abs(y-o.y) < eps; }
    pnt operator-(pnt o) { return pnt(x - o.x, y - o.y); }
    pnt operator*(T c) { return pnt(x*c, y*c); }
    T dot(pnt o) { return x*o.x + y*o.y; }
    T cross(pnt o) { return x*o.y - y*o.x; }
    T cross(pnt o1, pnt o2) { return (o1-*this).cross(o2-*this); }
    T mag2() { return dot(*this); }
    ld mag() { return sqrtl(mag2()); }
    pnt unit() { return *this * (1/mag()); }
    pnt perp() { return pnt(-y, x); }
    pnt norm() { return perp().unit(); }
    ld ang() { return atan2l(y, x); }
};
