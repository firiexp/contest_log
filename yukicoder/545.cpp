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

static const int MOD = 1000000007;
using ll = long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    int m = n/2; n -= m;
    vector<ll> a1(n), b1(n), a2(m), b2(m);
    for (int i = 0; i < n; ++i) {
        cin >> a1[i] >> b1[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> a2[i] >> b2[i];
    }
    vector<ll> v(1 << n), u(1 << m);
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if(i & (1 << j)) v[i] += a1[j];
            else v[i] -= b1[j];
        }
    }
    for (int i = 0; i < (1 << m); ++i) {
        for (int j = 0; j < m; ++j) {
            if(i & (1 << j)) u[i] += a2[j];
            else u[i] -= b2[j];
        }
    }
    sort(u.begin(),u.end());
    ll ans = INF<ll>;
    for (int i = 0; i < (1 << n); ++i) {
        auto x = lower_bound(u.begin(),u.end(), -v[i]);
        if(x != u.begin()) x--;
        for (int j = 0; j < 2; ++j) {
            if(x == u.end()) break;
            ans = min(ans, abs(*x+v[i]));
            x++;
        }
    }
    cout << ans << "\n";
    return 0;
}