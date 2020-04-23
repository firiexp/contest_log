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
    auto dp = make_v(2, 11, 101, -1);
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    dp[0][a1][a2] = a3;
    int b1, b2, b3, c1, c2, c3, d1, d2;
    cin >> d1 >> b1 >> b2 >> b3 >> d2 >> c1 >> c2 >> c3;
    int ok = 1, cnt = 0;
    for (int now = 0; ok; now ^= 1, cnt++) {
        ok = 0;
        int nxt = now^1;
        for (int i = 0; i <= 10; ++i) {
            for (int j = 0; j <= 100; ++j) {
                dp[nxt][i][j] = -1;
            }
        }
        for (int i = 0; i <= 10; ++i) {
            for (int j = 0; j <= 100; ++j) {
                if(~dp[now][i][j]){
                    int p = i, q = j, r = dp[now][i][j];
                    int required = d1;
                    int tmp = min(p, required/1000);
                    p -= tmp; required -= tmp*1000;
                    tmp = min(q, required/100);
                    q -= tmp; required -= tmp*100;
                    if(r-required >= 0){
                         chmax(dp[nxt][p+b1][q+b2], r-required+b3);
                         ok = 1;
                    }
                    p = i, q = j, r = dp[now][i][j];
                    required = d2;
                    tmp = min(p, required/1000);
                    p -= tmp; required -= tmp*1000;
                    tmp = min(q, required/100);
                    q -= tmp; required -= tmp*100;
                    if(r-required >= 0){
                        chmax(dp[nxt][p+c1][q+c2], r-required+c3);
                        ok = 1;
                    }
                }
            }
        }
    }
    cout << cnt-1 << "\n";
    return 0;
}