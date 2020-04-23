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
    vector<int> x(n), y(n), w(n);
    map<pair<int, int>, int> s;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &x[i], &y[i], &w[i]);
        s[{x[i], y[i]}] += w[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = -1; j < 1; ++j) {
            for (int k = -1; k < 1; ++k) {
                ll q = 0;
                for (int l = 0; l < 2; ++l) {
                    for (int m = 0; m < 2; ++m) {
                        q += s[{x[i]+j+l, y[i]+k+m}];
                    }
                }
                ans = max(ans, q);
            }
        }
    }
    printf("%lld / 1\n", ans);
    return 0;
}