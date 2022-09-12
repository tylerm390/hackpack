/**
 * Description: Returns the intersection point of two segments.
 * Usage: Returns a vector of points. If no points, there is no intersection. If 1 point, the segments intersect at a distinct point. If 2 points, the segments intersect at a segment of points, where the 2 points are the end points.
 * Status: Stress-Tested through Kattis::intersecton
 */
#pragma once

template<class P> vector<P> segInter(P s1, P e1, P s2, P e2) {
    if(doSegInter(s1, e1, s2, e2)) return {lineInter(s1, e1, s2, e2)};
	set<P> seg;
    if(onSeg(s1, e1, s2)) seg.insert(s2);
    if(onSeg(s1, e1, e2)) seg.insert(e2);
    if(onSeg(s2, e2, s1)) seg.insert(s1);
    if(onSeg(s2, e2, e1)) seg.insert(e1);
    return {all(seg)};
}