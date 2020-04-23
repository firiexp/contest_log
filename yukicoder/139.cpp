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
    int n, l;
    cin >> n >> l;
    ll ans = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        int x, w, t;
        cin >> x >> w >> t;
        ans += x-y; y = x;
        if(ans%(2*t) > t-w) ans = (ans/(2*t)+1)*2*t;
        ans += w; y += w;

    }
    ans += l-y;
    cout << ans << "\n";
    return 0;
}