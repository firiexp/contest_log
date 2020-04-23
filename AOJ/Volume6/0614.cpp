#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> c(n, 0), a(m);
    for (auto &&i : a) scanf("%lld", &i);
    for (int i = 0; i < m-1; ++i) {
        c[min(a[i], a[i+1])-1]++;
        c[max(a[i], a[i+1])-1]--;
    }
    ll S = 0;
    for (int i = 0; i < n+1; ++i) {
        S += c[i];
        c[i] = S;
    }
    ll ans = 0;
    for (int i = 0; i < n-1; ++i) {
        int p, q, r;
        scanf("%d %d %d", &p, &q, &r);
        ans += min(p*c[i], q*c[i]+r);
    }
    cout << ans << "\n";
    return 0;
}
