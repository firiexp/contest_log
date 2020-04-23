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
    int q;
    cin >> q;
    while(q--){
        ll x;
        scanf("%lld", &x);
        ll ans = 0;
        while(x%2 == 0) x /= 2, ans++;
        while(x%3 == 0) x /= 3, ans += 2;
        while(x%5 == 0) x /= 5, ans += 3;
        if(x != 1) puts("-1");
        else printf("%lld\n", ans);
    }

    return 0;
}