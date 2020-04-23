#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll x; int n;
    cin >> x >> n;
    vector<int> v(n+1);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i+1]);
    }
    v.emplace_back(INF<int>);
    int q;
    cin >> q;
    int cur = 1, c = 0;
    ll l = 0, r = x, lv = 0, rv = x;
    for (int i = 0; i < q; ++i) {
        int t, a;
        scanf("%d %d", &t, &a);
        while(v[cur] <= t){
            int dt = v[cur] - v[cur-1];
            if(c){
                l += dt, r += dt;
                if(x <= l) lv = rv = 0, l = r = x;
                else if(x <= r) rv -= r-x, r = x;
            }else {
                l -= dt, r -= dt;
                if(r <= 0) lv = rv = 0, l = r = 0;
                else if(l <= 0) lv -= l, l = 0;
            }
            c ^= 1;
            cur++;
        }
        int dt = t-v[cur-1];
        {
            ll l2 = l, r2 = r, lv2 = lv, rv2 = rv;
            if(c){
                l2 += dt, r2 += dt;
                if(x <= l2) lv2 = rv2 = 0, l2 = r2 = x;
                else if(x <= r2) rv2 -= r2-x, r2 = x;
            }else {
                l2 -= dt, r2 -= dt;
                if(r2 <= 0) lv2 = rv2 = 0, l2 = r2 = 0;
                else if(l2 <= 0) lv2 -= l2, l2 = 0;
            }
            if(a <= lv2) printf("%li\n", l2);
            else if(a <= rv2) printf("%li\n", l2+(a-lv2));
            else printf("%li\n", r2);
        }
    }
    return 0;
}
