#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <cmath>

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
    int n;
    cin >> n;
    vector<tuple<string, string, int>> v;
    vector<string> z;
    for (int i = 0; i < n; ++i) {
        string s, t; int m;
        cin >> s >> m >> t;
        v.emplace_back(s, t, m);
        z.emplace_back(s);
        z.emplace_back(t);
    }
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    auto g = [&](string s){return lower_bound(z.begin(), z.end(), s)- z.begin(); };
    size_t m = z.size();
    auto dp = make_v(m, m, 0.0);
    for (int i = 0; i < m; ++i) {
        dp[i][i] = 1.0;
    }
    for (int i = 0; i < n; ++i){
        string s, t; int k;
        tie(s, t, k) = v[i];
        dp[g(t)][g(s)] = k;
        dp[g(s)][g(t)] = 1.0/k;
    }
    string s, t; double ans = 0;
    for (int k = 0; k < m; ++k) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < m; ++j) {
                    if(dp[i][j] == 0 && dp[i][k]*dp[k][j] != 0) dp[i][j] = dp[i][k]*dp[k][j];
                    if(dp[i][j] == 0 && dp[i][k]*dp[j][k] != 0) dp[i][j] = dp[i][k]/dp[j][k];
                }
            }
        }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if(dp[i][j] > ans){
                s = z[i], t = z[j], ans = dp[i][j];
            }
        }
    }
    cout << 1 << t << "=" << (ll)(ans+1e-5) << s << "\n";
    return 0;
}
