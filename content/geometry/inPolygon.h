/**
 * Description: Uses the cutting-ray test to see if a point is inside a polygon.
 * Usage: Returns 0 if outside, 1 if strictly inside, and 2 if on.
 * Time: $O(n)$
 * Memory: $O(n)$
 * Status: tested on kattis::pointinpolygon
 */

template<class P> int inPoly(vector<P> poly, P p) {
    bool good = false; int n = sz(poly);
    auto crosses = [](P s, P e, P p) { 
        return ((e.y >= p.y) - (s.y >= p.y)) * p.cross(s, e) > 0; 
    };
    for(int i = 0; i < n; i++){
        if(onSeg(poly[i], poly[(i+1)%n], p)) return 2;
        good ^= crosses(poly[i], poly[(i+1)%n], p);
    }
    return good;
}