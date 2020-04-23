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
    int n;
    cin >> n;
    vector<ll> v(n), suml(n), sumr(n), l(n), r(n);
    ll S = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &v[i]);
        S += v[i];
        suml[i] = S;
    }
    S = 0;
    for (int i = 0; i < n; ++i) {
        S += v[n-i-1];
        sumr[n-i-1] = S;
    }
    map<ll, int> ml;
    ml[0] = 1;
    S = 0;
    for (int i = 0; i < n; ++i) {
        S += ml[suml[i]];
        l[i] = S;
        ml[suml[i]]++;
    }

    map<ll, int> mr;
    mr[0] = 1, S = 0;
    for (int i = n-1; i >= 0; --i) {
        S += mr[sumr[i]];
        r[i] = S;
        mr[sumr[i]]++;
    }
    ll ans = INF<ll>;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, (i ? l[i-1] : 0LL)+(i != n-1 ? r[i+1] : 0LL));
    }
    cout << ans << "\n";
    return 0;
}
