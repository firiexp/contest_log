#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cassert>
#include <set>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T>
T pow_ (T x, T n, T M){
    uint64_t u = 1, xx = x;
    while (n > 0){
        if (n&1) u = u * xx % M;
        xx = xx * xx % M;
        n >>= 1;
    }
    return static_cast<T>(u);
};


int main() {
    int n, m, k;
    cin >> n >> m >> k;

    if(k == 1){
        int ans = 0;
        if(n == 1) ans = 1;
        cout << ans << "\n";
        return 0;
    }
    if(n <= 8 && k <= 2){
        using P = pair<int, int>;
        vector<P> v;
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            v.emplace_back(a-1, b-1);
        }
        int ans = 0;
        for (int i = 0; i < (1 << n); ++i) {
            set<int> u;
            for (int j = 0; j < n; ++j) {
                if (i & (1<<j)) {
                    u.insert(j);
                }
            }
            bool valid = true;
            for (int j = 0; j < m; ++j) {
                if ((u.count(v[j].first) + u.count(v[j].second))%2 == 0){
                    valid = false;
                }
            }
            if(valid) ans++;
        }
        cout << ans << "\n";
    }else {
        ll ans = k%MOD;
        k *= pow_(k-1, n-1, MOD);
        cout << k%MOD << "\n";
    }
    return 0;
}
