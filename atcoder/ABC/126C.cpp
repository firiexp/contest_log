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
    int n, k;
    cin >> n >> k;
    long double ans = 0;
    for (int i = 1; i <= n; ++i) {
        long double a = 1.0L/n;
        int j = i, cnt = 0;
        while(j < k) j *= 2, cnt++;
        ans += a*pow(0.5L, cnt);
    }
    cout << setprecision(15) << ans << "\n";
    return 0;
}