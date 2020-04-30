#include <iostream>
#include <algorithm>
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
    vector<int> c(n), w(n);
    vector<int> Wsum(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> w[i];
        Wsum[i+1] = Wsum[i] + w[i];
    }

    auto dp = make_v(n, n, false);
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }
    for (int len = 1; len < n; ++len) {
        for (int i = 0, j = len; j < n; ++i, ++j) {
            if(dp[i+1][j] && Wsum[j+1]-Wsum[i+1] <= c[i]) dp[i][j] = true;
            if(dp[i][j-1] && Wsum[j]-Wsum[i] <= c[j]) dp[i][j] = true;
        }
    }
    vector<int> ans(n+1, INF<int>);
    ans[0] = 0;
    for (int i = 0; i < n; ++i) {
        int r = i+1;
        for (int j = i; j < n; ++j) {
            if(dp[i][j]) r = max(r, j+1);
        }
        for (int j = i+1; j <= r; ++j) {
            ans[j] = min(ans[j], ans[i]+1);
        }
    }
    cout << ans.back() << "\n";
    return 0;
}