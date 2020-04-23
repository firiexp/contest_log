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
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), a(n);
    for (auto &&i : x) scanf("%lld", &i);
    for (auto &&j : a) scanf("%lld", &j);
    m--;
    int l = m, r = m;
    ll lb = x[m]-a[m], ub = x[m]+a[m];
    while((0 < l && lb <= x[l-1]) || (r < n-1 && x[r+1] <= ub)){
        if((0 < l && lb <= x[l-1])){
            l--;
            lb = min(lb, x[l]-a[l]);
            ub = max(ub, x[l]+a[l]);
        }
        if((r < n-1 && x[r+1] <= ub)){
            r++;
            lb = min(lb, x[r]-a[r]);
            ub = max(ub, x[r]+a[r]);
        }
    }
    cout << r-l+1 << "\n";
    return 0;
}