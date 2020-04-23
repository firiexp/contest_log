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

int main() {
    string s;
    while(cin >> s, s != "0"){
        auto dp = make_v(s.size()+1, 11, 0LL);
        ll ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i] != '0') dp[i+1][s[i]-'0']++;
            for (int j = 0; j < 11; ++j) {
                dp[i+1][(j*10+s[i]-'0')%11] += dp[i][j];
            }
            ans += dp[i+1][0];
        }
        cout << ans << "\n";
    }
    return 0;
}