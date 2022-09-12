/**
 * Description: Finds the intersection between a circle and a line.
 * Returns a vector of either 0, 1, or 2 intersection points.
 * P is intended to be Point<double>.
 * Source: Kactl (To be Replaced)
 */

template<class P> vector<P> circleLine(P c, double r, P a, P b) {
	P ab = b - a, p = a + ab * (c-a).dot(ab) / ab.dist2();
	double s = a.cross(b, c), h2 = r*r - s*s / ab.dist2();
	if (h2 < 0) return {};
	if (h2 == 0) return {p};
	P h = ab.unit() * sqrt(h2);
	return {p - h, p + h};
}
