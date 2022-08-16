/**
 * Description: Uses shoelace theorem to find the area of a polygon. 
 * Usage: If area is negative, points are given cw, otherwise points are given ccw.
 * Time: $O(n)$
 * Memory: $O(n)$
 * Status: Tested on kattis::polygonarea
 */

#pragma once

template<class T> ld polyArea(vector<pnt<T>> poly) {
    int n = sz(poly); T area = 0;
    for(int i = 0; i < n; i++)
        area += poly[i].cross(poly[(i+1)%n]);
    return area / 2.0L;
}