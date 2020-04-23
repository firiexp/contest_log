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
    int n, d;
    cin >> n >> d;
    vector<int> v, u;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            v.emplace_back(i*i+j*j);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            u.emplace_back(i*i-j*j);
        }
    }
    sort(v.begin(), v.end());
    sort(u.begin(), u.end());
    for (auto &&i : v) {
        auto r = equal_range(u.begin(), u.end(), i-d);
        ans += r.second-r.first;
    }
    cout << ans << "\n";
    return 0;
}
