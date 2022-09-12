/**
 * Description: Returns whether or not a point is on a segment
 * Status: stress-tested via segIntersection.h
 */
#pragma once

template<class P> bool onSeg(P s, P e, P p) {
    return abs(s.cross(e, p)) < eps && (s-p).dot(e-p) < eps;
}