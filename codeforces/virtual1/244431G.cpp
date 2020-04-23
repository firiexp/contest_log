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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int ans = INF<int>;
    for (int i = 0; i <= n; ++i) {
        int price = i*b + max(0, n-i*m)*a;
        ans = min(ans, price);
    }
    cout << ans << "\n";
    return 0;
}