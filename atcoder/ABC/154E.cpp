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
    int k;
    cin >> s >> k;
    int n = s.size();
    auto dp = make_v(n+1, 2, k+1, 0UL);
    dp[0][0][0]= 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int l = 0; l <= k; ++l) {
                int d = j ? 9 : s[i]-'0';
                for (int x = 0; x <= d; ++x) {
                    if(l + (x!=0) <= k){
                        dp[i+1][j|(x < d)][l+(x!=0)] += dp[i][j][l];
                    }
                }
            }
        }
    }
    cout << dp[n][0][k]+dp[n][1][k] << "\n";
    return 0;
}