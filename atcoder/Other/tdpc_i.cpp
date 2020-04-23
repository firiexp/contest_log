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
    string s;
    cin >> s;
    int n = s.size();
    auto dp = make_v(n+1, n+1, -1);
    for (int i = 0; i <= n; ++i) {
        dp[i][i] = 0;
    }
    for (int len = 3; len <= n; len += 3) {
        for (int i = 0; i+len <= n; ++i) {
            int j = i+len;
            if(s[i] == 'i' && s[i+1] == 'w' && s[i+2] == 'i' && ~dp[i+3][j]) chmax(dp[i][j], dp[i+3][j]+1); // iwixx
            if(s[j-1] == 'i' && s[j-2] == 'w' && s[j-3] == 'i' && ~dp[i][j-3]) chmax(dp[i][j], dp[i][j-3]+1); // xxiwi
            if(s[i] == 'i' && s[j-1] == 'i'){
                for (int k = i+1; k < j-1; ++k) { // ixxwxxi
                    if(s[k] == 'w' && ~dp[i+1][k] && ~dp[k+1][j-1]) chmax(dp[i][j], dp[i+1][k]+dp[k+1][j-1]+1);
                }
            }

        }
    }
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i+len <= n; ++i) {
            chmax(dp[i][i+len], dp[i+1][i+len]);
            chmax(dp[i][i+len], dp[i][i+len-1]);
        }
    }
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i+len <= n; ++i) {
            int j = i+len;
            for (int k = i; k <= j; ++k) {
                if(~dp[i][k] && ~dp[k][j]) chmax(dp[i][j], dp[i][k]+dp[k][j]);
            };
        }
    }
    cout << dp[0][n] << "\n";
    return 0;
}