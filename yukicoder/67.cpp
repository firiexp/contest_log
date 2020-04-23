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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    double k;
    cin >> k;
    double ok = 0, ng = 1e15;
    for (int i = 0; i < 100; ++i) {
        auto mid = (ok+ng)/2;
        double s = 0;
        for (int j = 0; j < n; ++j) {
            s += floor(v[j]/mid);
        }
        (s >= k ? ok : ng) = mid;
    }
    printf("%.15lf\n", ok);
    return 0;
}