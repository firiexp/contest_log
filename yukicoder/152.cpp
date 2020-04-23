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
    int l;
    cin >> l;
    l /= 4;
    int ans = 0;
    for (int m = 1; m*m < l; ++m) {
        for (int n = (1+m%2); m*m+n*n < l && n < m; n += 2) {
            if(__gcd(n, m) > 1) continue;
            if(2*m*(m+n) <= l) {
                ans++;
            }
        }
    }
    cout << ans%1000003 << "\n";
    return 0;
}