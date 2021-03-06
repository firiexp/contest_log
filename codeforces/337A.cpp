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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(),v.end());
    int ans = INF<int>;
    for (int i = 0; i <= n-m; ++i) {
        ans = min(ans, v[i+m-1]-v[i]);
    }
    cout << ans << "\n";
    return 0;
}