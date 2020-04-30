#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {

    int n;
    cin >> n;
    vector<int> xs(n), rs(n);
    double ok = 0, ng = 1000000;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &xs[i], &rs[i]);
        if(ng > rs[i]) ng = rs[i];
    }
    for (int i = 0; i < 100; ++i) {
        double mid = (ok+ng)/2;
        double lb = -1e10, ub = 1e10;
        for (int j = 0; j < n; ++j) {
            double r = sqrt((ll)rs[j]*rs[j]-mid*mid);
            lb = max(lb, xs[j]-r);
            ub = min(ub, xs[j]+r);
        }
        if(ub >= lb) ok = mid;
        else ng = mid;
    }
    printf("%.15lf\n", ok);
    return 0;
}