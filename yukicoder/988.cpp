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

#include <cassert>
int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    char c;
    cin >> c;
    vector<ll> v(n), u(m);
    for (auto &&i : u) scanf("%lld", &i);
    for (auto &&j : v) scanf("%lld", &j);
    ll x = accumulate(v.begin(),v.end(), 0LL), y = accumulate(u.begin(),u.end(), 0LL);
    if(c == '+'){
        cout << (x%k*m%k+y%k*n%k)%k << "\n";
    }else {
        cout << x%k*(y%k)%k << "\n";
    }
    return 0;
}