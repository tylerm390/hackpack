/**
 * Description: Gets the distance between a point and a segment.
 */
#pragma once

template<class P> ld segDist(P s, P e, P p) {
    if(s == e) return (p - s).mag();
    auto d = (e-s).mag2(), t = min(d, max(0.0, (p-s).dot(e-s)));
    return ((p - s)*d - (e - s)*t).mag() / d;
}