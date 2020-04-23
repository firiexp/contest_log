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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

ll ddp(string s){
    auto dp = make_v(s.size()+1, 2, 2, 0LL);
    dp[0][0][0] = 1;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < 2; ++j) {
            int x = (j ? 9 : s[i]-'0');
            for (int k = 0; k < 2; ++k) {
                for (int e = 0; e <= x; ++e) {
                    dp[i+1][j || e < x][k || e == 4 || e == 9] += dp[i][j][k];
                }
            }
        }
    }
    ll ans = 0;
    for (int j = 0; j < 2; ++j) {
        ans += dp[s.size()][j][1];
    }
    return ans;
}

int main() {
    ll a, b;
    cin >> a >> b;
    a--;
    cout << ddp(to_string(b)) - ddp(to_string(a)) << "\n";
    return 0;
}
