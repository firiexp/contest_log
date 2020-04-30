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
    int h, n;
    cin >> h >> n;
    vector<int> grid(h, 15);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        grid[y] ^= (1 << x);
    }
    vector<array<int, 16>> dp(h);
    for (auto &&i : dp) fill(i.begin(),i.end(), -INF<int>);
    dp[0][grid[0]] = 0;
    for (int i = 1; i < h; ++i) {
        for (int S = 0; S < 16; ++S) {
            if(dp[i-1][S] < 0) continue;
            for (int T = grid[i]; ; T = grid[i]&(T-1)) {
                chmax(dp[i][T], dp[i-1][S]);
                if((S&3) == 3 && (T&3) == 3) chmax(dp[i][T^3], dp[i-1][S]+1);
                if((S&6) == 6 && (T&6) == 6) chmax(dp[i][T^6], dp[i-1][S]+1);
                if((S&12) == 12 && (T&12) == 12) chmax(dp[i][T^12], dp[i-1][S]+1);
                if((S&15) == 15 && (T&15) == 15) chmax(dp[i][T^15], dp[i-1][S]+2);
                if(!T) break;
            }
        }
    }
    cout << *max_element(dp.back().begin(),dp.back().end()) << "\n";
    return 0;
}