#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), c(3*n+1, INF<int>);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a[i], &b[i]);
    }
    for (int i = 0; i < n; ++i) {
        c[i] = a[i];
        c[i+n] = b[i]+1;
        c[i+n+n] = b[i];
    }
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    auto f = [&](int x){ return lower_bound(c.begin(), c.end(), x)-c.begin(); };
    vector<ll> r(c.size()+1);
    for (int i = 0; i < n; ++i) {
        r[f(a[i])]++;
        r[f(b[i]+1)]--;
    }
    for (int i = 0; i < c.size(); ++i) {
        r[i+1] += r[i];
    }
    ll cnt = 0;
    for (int i = 0; i < c.size(); ++i) {
        if(r[i] <= 0) continue;
        ll haba = (c[i+1]-c[i])*r[i];
        if(haba+cnt >= k){
            cout << c[i]+(k-cnt-1)/r[i] << "\n";
            return 0;
        }
        cnt += haba;
    }
    return 0;
}
