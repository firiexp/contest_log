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
    ll m, b;
    cin >> m >> b;
    ll ans = 0;
    for (ll y = 0; y <= b; ++y) {
        ll x = m*(b-y);
        ans = max(ans, (x+1)*(y+1)*(x+y)/2);
    }
    cout << ans << "\n";
    return 0;
}