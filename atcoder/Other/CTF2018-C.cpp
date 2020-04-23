#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;


int main() {
    int n;
    cin >> n;
    vector<ll> v(n), S(n+1, 0), IS(n+1, 0);
    for (auto &&i : v) scanf("%lld", &i);
    sort(v.begin(), v.end());
    ll ans = 0, sum = 0, isum = 0;
    for (int i = 0; i < n; ++i) {
        sum += v[i];
        S[i+1] = sum;
    }
    for (int i = 0; i < n; ++i) {
        isum += v[n - i - 1];
        IS[n - i - 1] = isum;
    }
    for (int i = 0; i < n; ++i) {
        ans += v[i]*i-S[i];
        ans += IS[i+1]-v[i]*(n-i-1);
    }
    cout << ans/2 << "\n";
    return 0;
}
