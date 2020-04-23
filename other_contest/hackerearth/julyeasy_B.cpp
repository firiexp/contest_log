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
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    for (int i = 0; i < n; ++i) {
        if(v[i] >= 0) v[i] = v[i]/x*x;
    }
    cout << accumulate(v.begin(),v.end(), 0LL) << "\n";
    return 0;
}