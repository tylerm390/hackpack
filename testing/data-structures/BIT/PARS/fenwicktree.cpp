#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;

#define lso(x) ((x) & -(x))

class bit {
    public:
        int n;
        vector<ll> ft;
        bit(int n) {
            this->n = n;
            ft.resize(n + 1);
            fill(ft.begin(), ft.end(), 0);
        }

        void update(int i, int val) {
            for (; i < (int) ft.size(); i += lso(i)) {
                ft[i] += val;
            }
        }

        ll rsq(int i) {
            ll ret = 0;
            for (; i; i -= lso(i)) {
                ret += ft[i];
            }
            
            return ret;
        }

        ll rsq(int i, int j) {
            return rsq(j) - rsq(i - 1);
        }
};

int main() {
    int n, Q; cin >> n >> Q;
    bit ft(n);
    for (int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        ft.update(i, tmp);
    }

    for (int i = 0; i < Q; i++) {
        int q; cin >> q;
        if (q == 0) {
            int a, x; cin >> a >> x;
            ft.update(a + 1, x);
        } else {
            int l, r; cin >> l >> r;
            cout << ft.rsq(l + 1, r) << endl;
        }
    }
    return 0;
}
