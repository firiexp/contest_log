#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll x, y, a1, a2, b1, b2, xx, yy, t;
    cin >> x >> y >> a1 >> a2 >> b1 >> b2 >> xx >> yy >> t;
    vector<ll> xs{x}, ys{y};
    ll M = 40000000000000001;
    while(true){
        if(xs.back() > M || ys.back() > M) break;
        ll xxx = xs.back(), yyy = ys.back();
        xs.emplace_back(a1*xxx+b1);
        ys.emplace_back(a2*yyy+b2);
    }
    int n = xs.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(abs(xs[i]-xx)+abs(ys[i]-yy) > t) continue;
        int val = 1, cur = i;
        ll tt = t - abs(xs[i]-xx)-abs(ys[i]-yy);
        while(cur+1 < n){
            if(tt < abs(xs[cur]-xs[cur+1])+abs(ys[cur]-ys[cur+1])) break;
            tt -= abs(xs[cur]-xs[cur+1])+abs(ys[cur]-ys[cur+1]);
            val++; cur++;
        }
        ans = max(ans, val);

        tt = t - abs(xs[i]-xx)-abs(ys[i]-yy);
        val = 1, cur = i;
        while(cur-1 >= 0){
            if(tt < abs(xs[cur]-xs[cur-1])+abs(ys[cur]-ys[cur-1])) break;
            tt -= abs(xs[cur]-xs[cur-1])+abs(ys[cur]-ys[cur-1]);
            val++; cur--;
        }
        ans = max(ans, val);

    }
    cout << ans << "\n";
    return 0;
}