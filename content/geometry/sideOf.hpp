/**
 * Description: Checks what side of the line a point is on. 
 * Returns -1 if the point is left, 1 if right, and 0 if on the line. 
 * Orientation is based off the unit vector of the line 
 */
#pragma once

template<class P> int sideOf(P s, P e, P p) {
    auto cp = s.cross(e, p);
    return (cp > eps) - (cp < -eps);
}