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
    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    for (int i = 0; i < n-1; ++i) {
        ans += (ans+k-2)/(k-1);
    }
    cout << ans-1 << "\n";
    return 0;
}