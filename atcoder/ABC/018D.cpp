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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, m, p, q, r;
    cin >> n >> m >> p >> q >> r;
    vector<vector<pair<int, int>>> v(n);
    for (int i = 0; i < r; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        v[x-1].emplace_back(y-1,z);
    }
    int ans = 0;
    for (int i = 0; i < (1<<n); ++i) {
        if(__builtin_popcount(i) != p) continue;
        vector<int> cnt(m);
        for (int j = 0; j < n; ++j) {
            if(i & (1 << j)){
                for (auto &&k : v[j]) {
                    cnt[k.first] += k.second;
                }
            }
        }
        sort(cnt.begin(),cnt.end(), greater<>());
        int w = 0;
        for (int j = 0; j < q; ++j) {
            w += cnt[j];
        }
        ans = max(ans, w);
    }
    cout << ans << "\n";
    return 0;
}