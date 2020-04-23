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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }


int main() {
    int n, p, q;
    cin >> n;
    scanf("%d/%d", &p, &q);
    auto t = make_v(n, n, 0);
    vector<pair<int, int>> S(n);
    for (int i = 0; i < n; ++i) {
        S[i].second = i;
        for (int j = 0; j < n; ++j) {
            cin >> t[i][j];
            S[i].first -= t[i][j];
        }
    }
    sort(S.begin(), S.end());
    auto v = make_v(n, n+1, n+1, 0.0L);
    for (int i = 0; i < n; ++i) {
        v[i][0][0] = 1.0L;
        for (int j = 0; j < n; ++j) {
            if(i != j){
                for (int k = 0; k < n; ++k) {
                    v[i][j+1][k+1-t[i][j]] += v[i][j][k] * p/q;
                    v[i][j+1][k+(t[i][j])] += v[i][j][k] * (q-p)/q;
                }
            }else {
                for (int k = 0; k <= n; ++k) {
                    v[i][j+1][k] += v[i][j][k];
                }
            }
        }
    }
    auto dp = make_v(n+1, n+1, 0.0L);
    for (int i = 0; i < n; ++i) {
        dp[S.front().second][i] = v[S.front().second][n][i];
    }
    for (int i = 0; i < n-1; ++i) {
        int a = S[i].second, b = S[i+1].second;
        for (int j = 0; j < n; ++j) {
            for (int k = j+(a > b); k < n; ++k) {
                dp[b][k] += dp[a][j] * v[b][n][k];
            }
        }
    }
    long double ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += dp[S.back().second][i];
    }
    cout << setprecision(15) << ans << "\n";
    return 0;
}
