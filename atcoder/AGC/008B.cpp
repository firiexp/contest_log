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
    ll sum = 0, sump = 0;
    cin >> n >> k;
    vector<ll> s(n+1, 0), s2(n+1, 0);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        sum += x;
        if(x > 0) sump += x;
        s[i+1] = sum;
        s2[i+1] = sump;
    }
    for (int i = 0; i < n-k+1; ++i) {
        ll x = sump - s2[i+k] + s2[i];
        if(s[i+k] > s[i]) x += s[i+k] - s[i];
        ans = max(x, ans);
    }
    cout << ans << "\n";
    return 0;
}
