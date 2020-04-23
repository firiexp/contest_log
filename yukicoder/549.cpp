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
    vector<int> v(n);
    int ans = 0;
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; ++i) {
        ans += v[i]/2;
    }
    ans += v[n-1];
    cout << ans << "\n";
    return 0;
}
