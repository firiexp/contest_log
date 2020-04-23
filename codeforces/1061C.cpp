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
vector<ll> divisor(ll n, int m)
{
  vector<ll> ret;
  for(ll i = 1; i * i <= n && i <= m; i++) {
    if(n % i == 0) {
        ret.push_back(i);
      if(i * i != n && (n/i) <= m) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret), greater<>());
  return(ret);
}

int main() {
    int n;
    cin >> n;
    vector<ll> v(n), dp(n+1, 0);
    dp[0] = 1;
    for (auto &&i : v) scanf("%lld", &i);
    for (int i = 0; i < n; ++i) {
        auto fact = divisor(v[i], i+1);
        for (auto &&j : fact) {
            (dp[j] += dp[j-1]) %= MOD;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        (ans += dp[i]) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
