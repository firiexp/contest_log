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
    int n, m, k;
    cin >> n >> m >> k;
    ll s = ((ll)k+1)*(2*m-k)/2;
    ll ans = n/s*(k+1);
    n %= s;
    for (int i = m; n >= 0;) {
        if(n < 0) break;
        n -= i;
        ans++;
        i--;
        if(i < m-k) i = m;
    }
    cout << ans << "\n";
    return 0;
}