#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;


template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n;
    cin >> n;
    vector<int> x(n), a(n);
    vector<vector<int>> child(n);
    for (auto &&i : x) scanf("%d", &i);
    for (int i = 1; i < n; ++i) {
        int y;
        scanf("%d", &y);
        a[i] = y-1;
        child[y-1].emplace_back(i);
    }
    vector<bool> valid(1<<n, true);
    vector<vector<int>> v(n+1);
    for (int i = 0; i < (1<<n); ++i) {
        for (int j = 0; j < n; ++j) {
            if((i & (1 << j))) for (auto &&k : child[j]) if((i & (1 << k)) == 0) valid[i] = false;
        }
        v[__builtin_popcount(i)].emplace_back(i);
    }
    vector<int> dp(1<<n, INF<int>);
    dp[0] = 0;
    vector<bool> u(n);
    for (int p = 1; p <= n; ++p) {
        for (auto &&i : v[p]) {
            if(!valid[i]) continue;
            fill(u.begin(), u.end(), true);
            int c = 0;
            for (int j = 0; j < n; ++j) {
                if(i & (1 << j)) for (auto &&k : child[j]) u[k] = false;
                else u[j] = false;
            }
            for (int j = 0; j < n; ++j) if(u[j] == true) c += x[j];
            for (int j = 0; j < n; ++j) {
                if(i & (1 << j) && valid[i - (1 << j)]){
                    int cost = c;
                    for (auto &&k : child[j]) cost += x[k];
                    chmax(cost, dp[i-(1 << j)]);
                    chmin(dp[i], cost);
                }
            }
        }
    }
    cout << dp[(1<<n)-1] << "\n";
    return 0;
}
