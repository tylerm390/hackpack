/**
 * Description: Gets the distance between a point and a line.
 */
#pragma once

template<class P> ld lineDist(P s, P e, P p) {
    return (e-s).cross(p-s) / (e-s).mag();
}