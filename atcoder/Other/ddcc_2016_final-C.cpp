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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    ll a, b, c;
    string s;
    cin >> a >> b >> c >> s;
    int n = s.size();
    vector<ll> dp1(n+1), dp2(n+1);
    dp1[1] = s.front() == '1';
    dp2[n-1] = s.back() == '0';
    for (int i = 1; i < n; ++i) {
        dp1[i+1] = dp1[i]+(s[i-1] != s[i]);
    }
    for (int j = n-2; j >= 0; --j) {
        dp2[j] = dp2[j+1] + (s[j+1] != s[j]);
    }
    ll ans = INF<ll>;
    for (int i = 0; i <= n; ++i) {
        chmin(ans, c*max(dp1[i], dp2[i])+a*i+b*(n-i));
    }
    cout << ans << "\n";
    return 0;
}
