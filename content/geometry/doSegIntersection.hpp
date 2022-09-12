/**
 * Description: Checks if two segments intersect (inclusive of intersections at endpoints)
 * Status: stress-tested via segIntersection.h
 */
#pragma once

template<class P> bool doSegInter(P s1, P e1, P s2, P e2) {
    return sideOf(s1, e1, s2) != sideOf(s1, e1, e2) && 
           sideOf(s2, e2, s1) != sideOf(s2, e2, e1);
}