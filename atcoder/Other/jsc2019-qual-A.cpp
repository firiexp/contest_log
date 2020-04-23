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
    int m, d;
    cin >> m >> d;
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= d; ++j) {
            int d1 = j%10, d10 = j/10;
            if(d1 < 2 || d10 < 2) continue;
            if(d1*d10 == i) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}