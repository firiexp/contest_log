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
    vector<string> v(5);
    for (int i = 0; i < 5; ++i) {
        cin >> v[i];
    }
    auto G = make_v(3, n, 0);
    for (int i = 0; i < n; ++i) {
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for (int j = 0; j < 5; ++j) {
            if(v[j][i] == 'B') cnt1++;
            else if(v[j][i] == 'W') cnt2++;
            else if(v[j][i] == 'R') cnt3++;
        }
        G[0][i] = 5-cnt1, G[1][i] = 5-cnt2, G[2][i] = 5-cnt3;
    }
    auto dp = make_v(3, n+1, INF<int>);
    dp[0][0] = dp[1][0] = dp[2][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if(j == k) continue;
                dp[k][i+1] = min(dp[k][i+1], dp[j][i]+G[k][i]);
            }
        }
    }
    cout << min({dp[0][n], dp[1][n], dp[2][n]}) << "\n";
    return 0;
}