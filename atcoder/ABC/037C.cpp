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
    int n, k;
    cin >> n >> k;
    vector<ll> v;
    ll x = 0;
    v.emplace_back(0);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d" ,&a);
        x += a;
        v.emplace_back(x);
    }
    ll ans = 0;
    for (int j = 0; j < n - k + 1; ++j) {
        ans += v[j+k]-v[j];
    }
    cout << ans << "\n";
    return 0;
}
