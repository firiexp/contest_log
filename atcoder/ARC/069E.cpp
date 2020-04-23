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
    int n;
    cin >> n;
    vector<ll> ans(n);
    vector<pair<ll, ll>> u(n+1);
    u[n] = make_pair(0, 0);
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        u[i] = make_pair(x, i);
    }
    sort(u.begin(), u.end(), greater<>());
    ll cur = 0, m = n+1;
    while(cur != n+1){
        if(u[cur].first != u[cur+1].first) {
            m = min(m, u[cur].second);
            ans[m] += (u[cur].first-u[cur+1].first)*(cur+1);
        }
        cur++;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}
