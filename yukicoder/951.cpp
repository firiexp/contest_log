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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }


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
    int n, k;
    cin >> n >> k;
    auto dp = make_v(2, 2, k+1, -INF<ll>);
    vector<pair<int, int>> P(n);
    for (int i = 0; i < n; ++i) {
        cin >> P[i].first >> P[i].second;
    }
    sort(P.begin(),P.end(), greater<>());
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int now = i&1, nxt = now^1;
        for (int j = 0; j <= k; ++j) {
            chmax(dp[nxt][0][j], dp[now][0][j]);
            chmax(dp[nxt][1][j], dp[now][1][j]);
            if(j+P[i].first <= k) chmax(dp[nxt][1][j+P[i].first], dp[now][0][j] + P[i].second);
            chmax(dp[nxt][0][j], dp[now][1][j] + P[i].second);
        }
    }
    ll ans = 0;
    for (int i = 0; i <= k; ++i) {
        chmax(ans, dp[n&1][0][i]);
        chmax(ans, dp[n&1][1][i]);
    }
    cout << ans << "\n";
    return 0;
}