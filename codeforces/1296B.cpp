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
    int t;
    cin >> t;
    while(t--){
        ll n;
        scanf("%lld", &n);
        ll ans = 0;
        while(n/10){
            ll x = n/10;
            ans += x*10;
            n = n-x*10+x;
        }
        printf("%lld\n", ans+n);
    }
    return 0;
}