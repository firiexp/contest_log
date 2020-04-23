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

int main() {
    ll n, p;
    cin >> n >> p;
    ll ans = 0;
    vector<ll> fact(n+1, 1);
    for (int i = 0; i < n; ++i) {
        fact[i+1] = (fact[i]*(i+1))%p;
    }
    for (int i = 1; i <= n; ++i) {
        (ans += (n-i+1)*(n-i+1)%p*fact[i]%p*fact[n-i]%p) %= p;
    }
    cout << ans << "\n";
    return 0;
}