/**
 * Description: Returns the center of mass for a polygon.
 * Time: O(n)
 * Memory: O(1)
 * Source: Kactl (To be Replaced)
 */

template<class P> P polygonCenter(const vector<P>& v) {
	P res(0, 0); double A = 0;
	for (int i = 0, j = sz(v) - 1; i < sz(v); j = i++) {
		res = res + (v[i] + v[j]) * v[j].cross(v[i]);
		A += v[j].cross(v[i]);
	}
	return res / A / 3;
}