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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<array<int, 26>> next(n + 1);
    for (int i = n; i >= 0; --i) {
        fill(next[i].begin(), next[i].end(), n);
        if(i != n){
            for (int j = 0; j < 26; ++j) {
                next[i][j] = next[i + 1][j];
            }
            next[i][s[i] - 'a'] = i;
        }
    }
    auto dp = make_v(n+1, n+1, 0);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int c = 0; c < 26; ++c) {
                if(next[i][c] == n) continue;
                dp[next[i][c]+1][j+1] = min(k+1, dp[next[i][c]+1][j+1] + dp[i][j]);
            }
        }
    }
    int ans = 0;
    for (int i = n; i >= 0; --i) {
        for (int j = 0; j <= n; ++j) {
            ans += min(dp[j][i], k)*(n-i);
            k -= min(dp[j][i], k);
        }
    }
    if(k) puts("-1");
    else cout << ans << "\n";
    return 0;
}