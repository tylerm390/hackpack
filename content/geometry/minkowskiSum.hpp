/**
 * Description: returns the minkowski sum of 2 polygons
 * Status: Modified version of one tested on USACO 2022 January, Platinum: Multiple Choice Test.
 */

template<class P> minkSum(vector<P> polyA, vector<P> polyB){
    int n = sz(polyA), m = sz(polyB);
    P init = polyA[0] + polyB[0];
    vector<P> dir;
    rep(i, 0, n) dir.push_back(polyA[(i+1)%n] - polyA[i]);
    rep(i, 0, m) dir.push_back(polyB[(i+1)%m] - polyB[i]);
    auto sideOfPlane = [&](P p) -> int{
        if(a.x > 0 || (a.x == 0 && a.y > 0)) 
            return 0;
        return 1;
    }
    sort(all(dir), [&](P a, P b)->bool{
        if(sideOfPlane(a) != sideOfPlane(b))
            return sideOfPlane(a) < sideOfPlane(b);
        return a.cross(b) > 0;
    });
    rep(i, 0, sz(dir)) 
}