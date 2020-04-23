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
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    ll z = abs(v[1]-v[0]);
    for (int i = 0; i < n-1; ++i) {
        z = __gcd(z, abs(v[i+1]-v[i]));
    }
    ll x = *max_element(v.begin(),v.end());
    ll y = 0;
    for (int i = 0; i < n; ++i) {
        y += (x-v[i])/z;
    }
    cout << y << " " << z << "\n";
    return 0;
}