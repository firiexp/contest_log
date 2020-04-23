#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> order(n), pp(n+1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        order[y-1].emplace_back(x-1);
    }
    for (int i = 0; i < (1<<n); ++i) {
        pp[__builtin_popcount(i)].emplace_back(i);
    }
    vector<ll> dp(1<<n, 0);
    dp[0] = 1;
    for (int p = 1; p <= n; ++p) {
        for (auto &&i : pp[p]) {
            for (int j = 0; j < n; ++j) {
                if (i & (1<<j)) {
                    bool valid = true;
                    for (auto &&k : order[j]) {
                        if(!(i & (1<<k))) valid = false;
                    }
                    if(valid) dp[i] += dp[i-(1<<j)];
                }
            }
        }
    }
    cout << dp[(1<<n)-1] << "\n";
    return 0;
}
