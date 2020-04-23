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
#include <cassert>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<int> as(n);
    for (int i = 0; i < n; i++) scanf("%d", &as[i]);
    for (int i = 0; i < n; i++) as[i] = (as[i]/1000+1)*1000;

    vector<int> cs{10000, 5000, 1000};
    vector<int> vs{z, y, x};
    for (int t = 0; t < 3; t++) {
        int c = cs[t], v = vs[t];
        for (int i = 0; i < n; i++) {
            int k = min(as[i] / c, v);
            as[i] -= c * k;
            v -= k;
        }
        sort(as.rbegin(), as.rend());
        for (int i = 0; i < min(n, v); i++) as[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (as[i]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}