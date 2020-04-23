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

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lli", &i);
    ll s = 0;
    ll ans = n*(n+1)/2;
    int l = 0, r = 0;
    while(r < n){
        s += v[r++];
        while(l < r && s >= k) s -= v[l++];
        ans -= r-l;
    }
    cout << ans << "\n";
    return 0;
}