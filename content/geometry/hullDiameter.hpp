/**
 * Description: Gets the furthest set of points on a convex polygon using rotating calipers
 * Time: O(n)
 * Memory: O(1)
 * Source: Kactl
 */

template<class P> pair<P, P> hullDiameter(vector<P> poly){
    int n = sz(poly);
    int j = 1;
    
    pair<ld, pair<P, P>> ans(0, pair<P, P>(poly[0], poly[0]));
    rep(i, 0, j){
        for(;; j = (j+1)%n){
            ans = max(ans, {(poly[i]-poly[j]).mag2(), {poly[i], poly[j]}});
            if((poly[(j+1)%n] - poly[j]).cross(poly[i+1] - poly[i]) >= 0)
                break;
        }
    }
    return ans.second;
}