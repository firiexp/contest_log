#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }
int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(1<<n, 0);
    for (int x = 0; x < (1<<n); ++x) {
        if(__builtin_popcount(x)%3 != n%3) continue;
        for (int i = 0; i < n; ++i) {
            if(!((1<<i) & x)) continue;
            if(s[i] == '0') continue;
            for (int j = i+1; j < n; ++j) {
                if(s[i] == s[j]) continue;
                if(!((1<<j) & x)) continue;
                for (int k = j+1; k < n; ++k) {
                    if(!((1<<k) & x)) continue;
                    if(s[j] != s[k]) continue;
                    chmax(dp[x], dp[x-(1<<i)-(1<<j)-(1<<k)]
                    + 100*(s[i]-'0') + 10*(s[j] - '0') + (s[k] - '0'));
                }
            }
        }
    }
    cout << dp.back() << "\n";
    return 0;
}
