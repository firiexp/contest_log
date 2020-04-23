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
    vector<int> v{100, 20, 10, 5, 1};
    int ans = 0;
    for (auto &&i : v) {
        ans += n/i;
        n %= i;
    }
    cout << ans << "\n";
    return 0;
}
