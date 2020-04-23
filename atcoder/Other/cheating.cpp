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
    cin >> m >> n;
    vector<int> xs(n), ys(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &xs[i], &ys[i]);
    }
    sort(xs.begin(),xs.end());
    sort(ys.begin(),ys.end());
    ll ng = -1, ok = INF<int>;
    while(ok-ng > 1){
        int mid = (ok+ng)/2;
        ll a = -INF<int>, b = -INF<int>;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if(a < xs[i]) cnt++, a = xs[i]+mid;
            if(b < ys[i]) cnt++, b = ys[i]+mid;
        }
        if(cnt <= m) ok = mid;
        else ng = mid;
    }
    cout << ok << "\n";
    return 0;
}