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

#define popcnt32 __builtin_popcount
#define popcnt64 __builtin_popcountll

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[a].emplace_back(b, i);
        G[b].emplace_back(a, i);
    }
    int m;
    cin >> m;
    vector<int> us(m), vs(m);
    vector<ll> inds(m);
    for (int i = 0; i < m; ++i) {
        cin >> us[i] >> vs[i];
        us[i]--; vs[i]--;
        ll v = 0;
        auto rec = [&](int x, int par, int dest, auto &&f) -> int {
            if(x == dest) return 1;
            for (auto &&j : G[x]) {
                if(j.first != par){
                    v += 1LL << j.second;
                    int ret = f(j.first, x, dest, f);
                    if(ret) return 1;
                    v -= 1LL << j.second;
                }
            }
            return 0;
        };
        rec(us[i], -1, vs[i], rec);
        inds[i] = v;
    }
    ll ans = 1LL << (n-1);
    for (int i = 1; i < (1 << m); ++i) {
        ll sign = (popcnt64(i)&1 ? -1 : 1), val = 0;
        for (int j = 0; j < m; ++j) {
            if(i & (1 << j))val |= inds[j];
        }
        ll x = 1LL << (n-1 - popcnt64(val));
        ans += x*sign;
    }
    cout << ans << "\n";
    return 0;
}