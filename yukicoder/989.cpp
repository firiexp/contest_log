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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    char c;
    cin >> c;
    vector<ll> v(n), u(m);
    for (auto &&i : u) scanf("%lld", &i);
    for (auto &&j : v) scanf("%lld", &j);
    sort(v.begin(),v.end());
    sort(u.begin(),u.end());
    ll ans = 0;
    if(c == '+'){
        for (int i = 0; i < n; ++i) {
            ans += u.end()-lower_bound(u.begin(),u.end(), k-v[i]);
        }
    }else {
        for (int i = 0; i < n; ++i) {
            ans += u.end()-lower_bound(u.begin(),u.end(), (k+v[i]-1)/v[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}