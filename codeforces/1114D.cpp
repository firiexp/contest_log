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

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    v.erase(unique(v.begin(), v.end()), v.end());
    n = v.size();
    auto dp = make_v(n, n, -1);
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 0;
    }
    auto rec = [&](int l, int r, auto &&f) -> int {
        if(~dp[l][r]) return dp[l][r];
        dp[l][r] = min(f(l+1, r, f), f(l, r-1, f))+1;
        if(v[l] == v[r]) dp[l][r] = min(dp[l][r], f(l+1, r-1, f)+1);
        return dp[l][r];
    };
    cout << rec(0, n-1, rec) << "\n";
    return 0;
}