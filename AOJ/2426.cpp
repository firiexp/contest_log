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
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x[i], &y[i]);
    }
    auto zx = x, zy = y;
    sort(zx.begin(), zx.end());
    zx.erase(unique(zx.begin(), zx.end()), zx.end());
    sort(zy.begin(), zy.end());
    zy.erase(unique(zy.begin(), zy.end()), zy.end());

    return 0;
}