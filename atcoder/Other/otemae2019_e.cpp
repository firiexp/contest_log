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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<ll> S(n+1);
    for (int i = 0; i < n; ++i) {
        S[n-i-1] = S[n-i] - v[i];
    }
    for (int i = 0; i < q; ++i) {
        ll t, l, r;
        scanf("%lld %lld %lld", &t, &l, &r);
        cout << lower_bound(S.begin(),S.end(), r-t+1)-lower_bound(S.begin(),S.end(), l-t) << "\n";
    }
    return 0;
}