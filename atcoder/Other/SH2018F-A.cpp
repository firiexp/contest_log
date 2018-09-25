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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    ll c, d;
    cin >> c >> d;
    ll p = 70, q = 85;
    ll ans = 0;
    for (int i = 0; i <= 46; ++i) {
        p*=2, q*= 2;
        ans += max(min(q-1,d-1)-max(c,p)+1,0LL);
    }
    cout << ans << "\n";
    return 0;
}
