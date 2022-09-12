/**
 * Description: Determine whether a point t lies inside a convex hull (CCW
 * order, with no collinear points). Returns true if point lies within
 * the hull. If strict is true, points on the boundary aren't included.
 * Source: Kactl (To be replaced)
 * Status: stress-tested
 * Time: O(\log N)
 */

template<class P> bool inHull(const vector<P>& l, P p, bool strict = true) {
	int a = 1, b = sz(l) - 1, r = !strict;
	if (sz(l) < 3) return r && onSegment(l[0], l.back(), p);
	if (sideOf(l[0], l[a], l[b]) > 0) swap(a, b);
	if (sideOf(l[0], l[a], p) >= r || sideOf(l[0], l[b], p)<= -r)
		return false;
	while (abs(a - b) > 1) {
		int c = (a + b) / 2;
		(sideOf(l[0], l[c], p) > 0 ? b : a) = c;
	}
	return sgn(l[a].cross(l[b], p)) < r;
}