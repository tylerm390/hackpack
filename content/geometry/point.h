/*
 * Author: Tyler Marks
 * Description: Handles vector/point operations in the cartesian plane
 */

#pragma once

template<class T> struct pnt {
    T x, y;
    pnt(int _x = 0, int _y = 0): x(_x), y(_y) {}
    bool operator<(pnt o) { return pii(x, y) < pii(o.x, o.y); }
    bool operator==(pnt o) { return pii(x, y) == pii(o.x, o.y); }
    pnt operator+(pnt o) { return pnt(x + o.x, y + o.y); }
    pnt operator-(pnt o) { return pnt(x - o.x, y - o.y); }
    pnt operator*(T c) { return pnt(x*c, y*c); }
    T dot(pnt o) { return x*o.x + y*o.y; }
    T cross(pnt o) { return x*o.y - y*o.x; }
    T cross(pnt o1, pnt o2) { return (o1-*this).cross(o2-*this); }
    T dist2() { return dot(*this); }
    ld dist() { return sqrt(dist2()); }
    pnt unit() { return *this * (1/dist()); }
    pnt perp() { return pnt(-y, x); }
    pnt norm() { return perp().unit(); }
    ld ang() { return atan2l(y, x); }
};
