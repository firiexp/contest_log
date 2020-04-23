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


vector<ll> divisor(ll n)
{
  vector<ll> ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return(ret);
}

int main() {
    int n;
    cin >> n;
    ll ma = 0, mi = 0;
    map<ll, int> m;
    for (int i = 0; i < n; ++i) {
        ll k;
        scanf("%lld", &k);
        ma = max(ma, k);
        m[k]++;
    }
    auto b = divisor(ma);
    for (auto &&j : b) {
        m[j]--;
    }
    for (auto &&i : m) {
        if(i.second) mi = max(mi, i.first);
    }
    printf("%lld %lld\n", ma, mi);
    return 0;
}
