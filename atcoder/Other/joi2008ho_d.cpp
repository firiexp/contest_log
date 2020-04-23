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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, m;
    while(cin >> n >> m, n){
        auto dp = make_v(n, m+1, 10, INF<int>);
        vector<vector<pair<int, int>>> v(n);
        vector<int> cnt(n);
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            for (int j = 0; j < k; ++j) {
                int x, d;
                cin >> x >> d;
                v[i].emplace_back(x, d);
                if(i == 0){
                    dp[i][0][j] = 0;
                }else if(i == 1 && m){
                    dp[i][1][j] = 0;
                }
            }
        }
        for (int i = 0; i < n-1; ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k < v[i].size(); ++k) {
                    for (int l = 0; l < v[i+1].size(); ++l) {
                        chmin(dp[i+1][j][l], dp[i][j][k]+(v[i][k].second+v[i+1][l].second)
                                                         *abs(v[i][k].first-v[i+1][l].first));
                    }
                }
                if(i != n-2 && j != m){
                    for (int k = 0; k < v[i].size(); ++k) {
                        for (int l = 0; l < v[i+2].size(); ++l) {
                            chmin(dp[i+2][j+1][l], dp[i][j][k]+(v[i][k].second+v[i+2][l].second)
                                                               *abs(v[i][k].first-v[i+2][l].first));
                        }
                    }
                }
            }
        }
        int ans = INF<int>;
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k < v[n-1].size(); ++k) {
                chmin(ans, dp[n-1][j][k]);
            }
        }
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < v[n-2].size(); ++k) {
                chmin(ans, dp[n-2][j][k]);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}