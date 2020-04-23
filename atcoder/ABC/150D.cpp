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
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i), i /= 2;
    ll val = 1, p = 1LL << 31;
    for (int i = 0; i < n; ++i) {
        if(val > m){
            puts("0");
            return 0;
        }
        val = val/__gcd(val, v[i])*v[i];
        p = __gcd(p, v[i]);
    }
    if(val > m){
        puts("0");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if(v[i]/p%2 == 0){
            puts("0");
            return 0;
        }
    }
    cout << (m/val+1)/2 << "\n";
    return 0;
}