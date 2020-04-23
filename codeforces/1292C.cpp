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


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    vector<ll> v(n), dp(n);
    auto dfs1 = [&](int x, int par, auto &&f) -> void {
        for (auto &&y : G[x]) {
            if(y != par){
                f(y, x, f);
                v[x] += v[y];
            }
        }
    };
    auto dfs2 = [&](int x, int par, int val, auto &&f) -> void {
        for (auto &&y : G[x]) {
            if(y != par){
                dp[x] = dp[par] + v[x]*val;
                f(y, x, val+1, f);
            }
        }
    };
    ll ans = 0;
    for (int s = 0; s < n; ++s) {
        for (auto &&t : G[s]) {
            fill(v.begin(),v.end(), 1);
            fill(dp.begin(),dp.end(), 0);
            dfs1(t, s, dfs1);
            dfs2(t, s, n-v[t], dfs2);
            ans = max(ans, *max_element(dp.begin(),dp.end()));
            cout << s << " " << t << "\n";
            cout << v << "\n";
            cout << dp << "\n";
        }
    }
    cout << ans << "\n";
    return 0;
}