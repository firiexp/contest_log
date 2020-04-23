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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int d, n, m;
    cin >> d >> n >> m;
    vector<int> v(n+1);
    for (int i = 1; i < n; ++i) scanf("%d", &v[i]);
    v[n] = d;
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        int k = static_cast<int>(upper_bound(v.begin(), v.end(), x) - v.begin());
        ans += min(abs(v[k]-x), abs(v[k-1]-x));
    }
    cout << ans << "\n";
    return 0;
}
