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
    int n;
    cin >> n;
    vector<int> xs(n), ys(n), zs(n+1);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &xs[i], &ys[i]);
        zs[i] = max(xs[i], ys[i]);
    }
    sort(zs.begin(), zs.end());
    zs.erase(unique(zs.begin(), zs.end()), zs.end());
    int m = zs.size();
    vector<int> ls(m, INF<int>), rs(m, -INF<int>);
    for (int i = 0; i < n; ++i) {
        int p = lower_bound(zs.begin(),zs.end(), max(xs[i], ys[i])) - zs.begin();
        ls[p] = min(ls[p], xs[i]-ys[i]), rs[p] = max(rs[p], xs[i]-ys[i]);
    }
    auto g = [&](int a, int b) -> pair<int, int> {
        if(b >= 0) return {a, a-b};
        else return {a+b, a};
    };
    ll lans = 0, rans = 0;
    ll lx = 0, rx = 0, ly = 0, ry = 0;
    for (int i = 1; i < m; ++i) {
        ll lx2, ly2, rx2, ry2;
        ll lans2, rans2;
        tie(lx2, ly2) = g(zs[i], ls[i]); tie(rx2, ry2) = g(zs[i], rs[i]);
        lans2 = min({
            lans + abs(lx-lx2)+abs(ly-ly2) + 2*(abs(lx2-rx2)+abs(ly2-ry2)),
            lans + abs(lx-rx2)+abs(ly-ry2) + (abs(lx2-rx2)+abs(ly2-ry2)),
            rans + abs(rx-lx2)+abs(ry-ly2) + 2*(abs(lx2-rx2)+abs(ly2-ry2)),
            rans + abs(rx-rx2)+abs(ry-ry2) + (abs(lx2-rx2)+abs(ly2-ry2)),
            });
        rans2 = min({
            lans + abs(lx-lx2)+abs(ly-ly2) + (abs(lx2-rx2)+abs(ly2-ry2)),
            lans + abs(lx-rx2)+abs(ly-ry2) + 2*(abs(lx2-rx2)+abs(ly2-ry2)),
            rans + abs(rx-lx2)+abs(ry-ly2) + (abs(lx2-rx2)+abs(ly2-ry2)),
            rans + abs(rx-rx2)+abs(ry-ry2) + 2*(abs(lx2-rx2)+abs(ly2-ry2)),
            });
        lx = lx2, rx = rx2, ly = ly2, ry = ry2;
        lans = lans2, rans = rans2;
    }
    cout << min(lans, rans) << "\n";
    return 0;
}