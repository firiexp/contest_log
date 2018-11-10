#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T>
vector<T> make_v(size_t size, const T& init){ return vector<T>(size, init); }

template<class... Ts>
auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }



int main() {
    string s;
    cin >> s;
    auto dp = make_v(s.length()+1, 101, 101, INF<int>);
    dp[0][0][0] = 0;
    for (int i = 0; i < s.length(); ++i) {
        for (int j = 0; j < i+1; ++j) {
            for (int k = 0; k < 101; ++k) {
                if(dp[i][j][k] != INF<int>){
                    if(s[i] == '('){
                        // 置き換える
                        dp[i+1][j][k+1] = min(dp[i+1][j][k+1], dp[i][j][k]);
                        // 置き換えない
                        if(k) dp[i+1][i][k-1] = min(dp[i+1][i][k-1], dp[i][j][k]+1);
                    }else {
                        // 置き換える
                        if(k) dp[i+1][j][k-1] = min(dp[i+1][j][k-1], dp[i][j][k]);
                        // 置き換えない
                        dp[i+1][i][k+1] = min(dp[i+1][i][k+1], dp[i][j][k]+1);
                    }
                }
            }
        }
    }
    int ans = INF<int>;
    for (int j = 0; j < 101; ++j) {
        ans = min(ans, dp[s.length()][j][0] + j);
    }
    cout << ans << "\n";
    return 0;
}
