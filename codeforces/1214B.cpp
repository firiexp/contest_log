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
    int b, g, n;
    cin >> b >> g >> n;
    int ans = 0;
    for (int i = 0; i <= b; ++i) {
        for (int j = 0; j <= g; ++j) {
            if(i+j == n) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}