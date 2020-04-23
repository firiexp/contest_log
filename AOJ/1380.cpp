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
    ll n, t;
    cin >> n >> t;
    ll M = 0, S = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        scanf("%lld", &x);
        M = max(M, x);
        if(t <= S) puts("1");
        else printf("%lld\n", (t-S+M-x)/M+1);
        S += x;
    }
    return 0;
}