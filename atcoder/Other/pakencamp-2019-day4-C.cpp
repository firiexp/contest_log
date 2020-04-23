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
    ll l1, r1, l2, r2, l3, r3;
    cin >> l1 >> r1 >> l2 >> r2 >> l3 >> r3;
    ll ans = 0;
    for (int i = l1; i <= r1; ++i) {
        ans += max(0LL, r2-max<ll>(i, l2-1))* max(0LL, r3-max<ll>(i, l3-1));
    }
    printf("%.10lf\n", 1.0*ans/(r1-l1+1)/(r2-l2+1)/(r3-l3+1));
    return 0;
}