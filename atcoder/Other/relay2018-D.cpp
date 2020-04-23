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
    int n;
    cin >> n;
    vector<int> x(n), w(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x[i], &w[i]);
    }
    long double ng = 0, ok = INF<ll>, l, r, mid;
    for (int i = 0; i < 400; ++i) {
        l = -INF<ll>, r = INF<ll>, mid = (ok+ng)/2;
        for (int j = 0; j < n; ++j) {
            l = max(l, x[j]-abs(mid/w[j]));
            r = min(r, x[j]+abs(mid/w[j]));
        }
        if(l < r) ok = mid;
        else ng = mid;
    }
    l = -INF<ll>, r = INF<ll>;
    for (int j = 0; j < n; ++j) {
        l = max(l, x[j]-abs(ok/w[j]));
        r = min(r, x[j]+abs(ok/w[j]));
    }
    cout << setprecision(15) << l << "\n";
    return 0;
}