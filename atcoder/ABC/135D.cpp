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
    string s;
    cin >> s;
    int n = s.size();
    auto dp = make_v(n+1, 13, 0);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        if(s[i] != '?'){
            for (int j = 0; j < 13; ++j) {
                (dp[i+1][(j*10+s[i]-'0')%13] += dp[i][j]) %= MOD;
            }
        }else {
            for (int j = 0; j < 13; ++j) {
                for (int k = 0; k < 10; ++k) {
                    (dp[i+1][(j*10+k)%13] += dp[i][j]) %= MOD;
                }
            }
        }
    }
    cout << dp.back()[5] << "\n";
    return 0;
}