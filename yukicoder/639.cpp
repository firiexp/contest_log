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

map<ll, ll> m;


ll f(ll n){
    if(m.count(n)) return m[n];
    return (m[n] = f(n/3)+f(n/5));
}

int main() {
    ll n;
    cin >> n;
    m[0] = 1;
    cout << f(n) << "\n";
    return 0;
}