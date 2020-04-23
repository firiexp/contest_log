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
    vector<double> ps(n), qs(n);
    for (int i = 0; i < n; ++i) cin >> ps[i], ps[i] /= 1000;
    for (int i = 0; i < n; ++i) cin >> qs[i], qs[i] /= 100;
    priority_queue<pair<double, int>> p;
    for (int i = 0; i < n; ++i) {
        p.emplace(ps[i]*qs[i], i);
    }
    double ans = 0;
    for (int i = 0; i < n*1000; ++i) {
        double x; int cur; tie(x, cur) = p.top(); p.pop();
        ans += (i+1)*x;
        p.emplace(x*(1-qs[cur]), cur);
    }
    printf("%.10lf\n", ans);
    return 0;
}