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
    vector<int> xs(n), ys(n);
    for (int i = 0; i < n; ++i) {
        cin >> xs[i] >> ys[i];
    }
    double ans1 = 0, ans2 = 0;
    vector<int> v(n);
    iota(v.begin(),v.end(), 0);
    do {
        ans2 += 1;
        for (int i = 0; i < n - 1; ++i) {
            ans1 += hypot(xs[v[i]]-xs[v[i+1]], ys[v[i]]-ys[v[i+1]]);
        }
    }while(next_permutation(v.begin(),v.end()));
    printf("%.10lf\n", ans1/ans2);
    return 0;
}