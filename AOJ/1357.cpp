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
    vector<double> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = v[i];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            a[i] = max(a[i], a[j]+sqrt(4*v[i]*v[j]));
        }
    }
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, a[i]+v[i]);
    }
    printf("%.8lf", ans);
    return 0;
}