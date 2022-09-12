/**
 * Description: Returns the intersection point of two lines using cramers rule.
 * If the lines are parallel or are the same, (inf, inf) is returned.
 * Status: stress-tested via segIntersection.h
 */
#pragma once

template<class P> P lineInter(P s1, P e1, P s2, P e2) {
    auto det = -(e1-s1).cross(e2-s2);
    if(abs(det) < eps) return P(inf, inf);
    auto t = (e2-s2).cross(s2-s1) / det;
    return s1 + (e1-s1) * t;
}