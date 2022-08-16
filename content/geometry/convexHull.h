/**
 * Description: gets the smallest convex polygon containing all points using monotone chaining.
 * Time: $O(n\log{n})$
 * Memory: $O(n)$
 */

template<class P> vector<P> convexHull(vector<P> poly){
    int n = sz(poly);
    vector<P> hull(n+1);
    sort(all(poly));
    int k = 0;
    for(int i = 0; i < n; i++){
        while(k >= 2 && hull[k-2].cross(hull[k-1], poly[i]) <= 0) k--;
        hull[k++] = poly[i];
    }
    for(int i = n-1, t = k+1; i > 0; i--){
        while(k >= t && hull[k-2].cross(hull[k-1], poly[i-1]) <= 0) k--;
        hull[k++] = poly[i-1];
    }
    hull.resize(k-1);
    return hull;
}