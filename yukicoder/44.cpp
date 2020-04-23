#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<ll> ans(n+1, 1);
    for (int i = 2; i <= n; ++i) {
        ans[i] = ans[i-1] + ans[i-2];
    }
    cout << ans[n] << "\n";
    return 0;
}
