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
    int n, q;
    cin >> n >> q;
    vector<ll> v1(n), vsum(n+1, 0);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        ll a;
        scanf("%lld", &a);
        sum += a;
        v1[i] = a;
        vsum[i+1] = sum;
    }
    for (int i = 0; i < q; ++i) {
        ll c, d, ans = 0;
        scanf("%lld %lld", &c, &d);
        ll p = lower_bound(v1.begin(), v1.end(), c - d) - v1.begin(),
        p2 = lower_bound(v1.begin(), v1.end(), c) - v1.begin(),
        p3 = upper_bound(v1.begin(), v1.end(), c+d) - v1.begin();
        ans += d*p;
        if(p2 > p) ans += c*(p2-p)-vsum[p2]+vsum[p];
        if(p3 > p2) ans += vsum[p3]-vsum[p2] - c*(p3-p2);
        if(n > p3) ans += d*(n-p3);
        cout <<  ans << "\n";
    }
    return 0;
}
