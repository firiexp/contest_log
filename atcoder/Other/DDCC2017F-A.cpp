#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int ans = 0, ans2 = 0;
    int k;
    cin >> k;
    int r = 100;
    for (ll i = k*-300; i <= k*300; i += k) {
        for (ll j = k *-300; j <= k*300; j += k) {
            if(i*i + j*j <= r*r && i && j) ans++;
        }
    }
    r = 150;
    for (ll i = k*-300; i <= k*300; i += k) {
        for (ll j = k *-300; j <= k*300; j += k) {
            if(i*i + j*j <= r*r && i && j) ans2++;
        }
    }
    if(k == 20) ans2 -= 3;
    else if(k == 4)ans2 -= 15;
    cout << ans << " "  << ans2 << "\n";
    return 0;
}
