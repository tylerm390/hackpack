/**
 * Description: returns the minkowski sum of several polygons
 * Status: Tested on USACO 2022 January, Platinum: Multiple Choice Test.
 */

template<class P> vector<P> minkSum(vector<vector<P>> &polys){
    P init(0, 0);
    vector<P> dir;
    for(auto poly: polys) {
        int n = sz(poly);
        if(n == 0)
            continue;
        init = init + poly[0];
        if(n == 1)
            continue;
        rep(i, 0, n)
            dir.push_back(poly[(i+1)%n] - poly[i]);
    }
    if(size(dir) == 0)
        return {init};
    sort(all(dir), [&](P a, P b)->bool {
        bool sideA = a.x > 0 || (a.x == 0 && a.y > 0);
        bool sideB = b.x > 0 || (b.x == 0 && b.y > 0);
        if(sideA != sideB)
            return sideA;
        return a.cross(b) > 0;
    });
    vector<P> sum;
    P cur = init;
    rep(i, 0, sz(dir)) {
        sum.push_back(cur);
        cur = cur + dir[i];
    }
    return sum;
}
