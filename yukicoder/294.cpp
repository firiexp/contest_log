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
    int M = 30;
    auto dp = make_v(M+1, 3, 2, 0);
    dp[0][2][1] = 1;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    dp[i+1][(j+l*2)%3][l] += dp[i][j][k];
                }
            }
        }
        if(dp[i+1][0][0] + dp[i+1][0][1] >= n){
            M = i+1;
            break;
        }else n -= dp[i+1][0][0] + dp[i+1][0][1];
    }
    int val = 0;
    string ans;
    for (int i = M; i >= 2; --i) {
        if(dp[i][val][0] >= n){
            ans += '3';
        }else {
            ans += '5';
            n -= dp[i][val][0];
            val = (val+1)%3;
        }
    }
    val %= 3;
    if(val == 1) ans += '5';
    else ans += '3';
    ans += '5';
    cout << ans << "\n";
    return 0;
}