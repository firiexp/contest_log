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
#include <cassert>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() { // これは星2.5ではないです
    int n;
    cin >> n;
    ll ans = 0;
    vector<ll> v(n), S(n + 1);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &v[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        S[i + 1] = S[i] + v[i];
    }
    for (ll i = 1; i <= n; ++i) {
        int ok = 0;
        int ng = min(i, n-i-1) + 1;

        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            ((v[i-mid] + v[n-mid] - 2 * v[i] > 0) ? ok : ng) = mid;
        }
        ans = max(ans, S[i] - S[i - ok] + S[n] - S[n - ok] - v[i] * (2*ok));
    }
    cout << ans << "\n";
    return 0;
}