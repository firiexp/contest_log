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
    vector<int> A(n), B(n);
    for (auto &&i : A) scanf("%d", &i);
    for (auto &&i : B) scanf("%d", &i);
    auto dp = make_v(n, 1 << n, INF<int>), dp2 = dp;
    auto cnt = make_v(1 << n, 0);
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            dp2[j][i] = 0;
            if ((i >> j) & 1)continue;
            for (int k = j + 1; k < n; k++) {
                if ((i >> k) & 1)dp2[j][i]++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        dp[i][1 << i] = 0;
    }
    for (int i = 0; i < 1 << n; ++i) {
        cnt[i] = __builtin_popcount(i)-1;
    }
    for (int i = 0; i < 1 << n; i++) {
        int used = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) used++;
        }
        for (int j = 0; j < n; j++) {
            if (dp[j][i] == INF<int>)continue;
            int val = 0;
            if (used % 2 != j % 2) val = A[j];
            else val = B[j];
            for (int k = 0; k < n; k++) {
                if ((i >> k) & 1)continue;
                int c = 0;
                if (used % 2 == k % 2)c = A[k];
                else c = B[k];
                if (val > c)continue;
                dp[k][i | (1 << k)] = min(dp[k][i | (1 << k)], dp[j][i] + dp2[k][i]);
            }
        }
    }
    int ans = INF<int>;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dp[i].back());
    }
    if(ans == INF<int>){
        puts("-1");
    }else {
        cout << ans << "\n";
    }
    return 0;
}