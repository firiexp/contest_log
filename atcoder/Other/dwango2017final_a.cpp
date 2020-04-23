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

struct range {
    int max;
    int min;
    range(int min, int max) : max(max), min(min) {};
    bool operator==(const range &a){ return (a.max == max) && (a.min == min); }

    void ch(const range &a){
        max = std::max(max, a.max);
        min = std::min(min, a.min);
    }
};



int main() {
    int x; string s;
    cin >> x >> s;
    const range NG = range(INF<int>, -INF<int>);
    int n = static_cast<int>(s.size());
    auto dp = make_v(n+1, n+1, n+1, NG);
    for (int sz = 1; sz <= n; ++sz) {
        for (int l = 0; l < n; ++l) {
            int r = l+sz;
            if(r > n) continue;
            if(sz == 1){
                if('0' <= s[l] && s[l] <= '9') dp[l][r][0] = range(s[l]-'0', s[l]-'0');
                dp[l][r][1] = range(0, 9);
            }else {
                for (int k = 1; k < sz-1; ++k) {
                    int mid = l+k;
                    for (int ch1 = 0; ch1 < n; ++ch1) {
                        for (int ch2 = 0; ch2+ch1 < n; ++ch2) {
                            if(dp[l][mid][ch1] == NG || dp[mid][r-1][ch2] == NG) continue;
                            dp[l][r][ch1+ch2+(s[r-1] != '+')].ch(
                                    range(dp[l][mid][ch1].min + dp[mid][r-1][ch2].min,
                                            dp[l][mid][ch1].max + dp[mid][r-1][ch2].max));
                            dp[l][r][ch1+ch2+(s[r-1] != '-')].ch(
                                    range(dp[l][mid][ch1].min - dp[mid][r-1][ch2].max,
                                            dp[l][mid][ch1].max - dp[mid][r-1][ch2].min));
                        }
                    }
                }
            }
        }
    }
    int ans = -INF<int>;
    for (int i = 0; i <= x; ++i) {
        ans = max(ans, dp[0][n][i].max);
    }
    if(ans == -INF<int>){
        puts("NG");
        return 0;
    }
    puts("OK");
    cout << ans << "\n";
    return 0;
}
