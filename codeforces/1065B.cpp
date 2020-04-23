#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        if(i*(i-1)/2 >= m) break;
        ans++;
    }
    cout << max(n-2*m, 0LL) << " " << max(m ? n-ans-1: n, 0LL) << "\n";
    return 0;
}
