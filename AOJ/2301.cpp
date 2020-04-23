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

double p, e, t;

double solve(double l, double r, double k){
    double mid = (l+r)/2;
    if(k == 0) return 1.0*(abs(mid-t) < e);
    if(t - e <= l && r <= t + e) return 1.0;
    if(r < t - e || t + e < l) return 0.0;
    double ret = 0;
    if(mid <= t) ret += p*solve(l, mid, k-1)+(1-p)*solve(mid, r, k-1);
    else ret += (1-p)*solve(l, mid, k-1)+p*solve(mid, r, k-1);
    return ret;
}

int main() {
    double k, r, l;
    cin >> k >> l >> r >> p >> e >> t;
    printf("%.6f", solve(l, r, k));
    return 0;
}