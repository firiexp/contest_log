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

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }
int main() {
    int n, m;
    cin >> m >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(), v.end());
    int ans = INF<int>;
    for (int i = 0; i < n-m+1; ++i) {
        int x = v[i], y = v[i+m-1];
        chmin(ans, (x*y >= 0 ? max(abs(x), abs(y)) : abs(y-x)+min(abs(y), abs(x))));
    }
    cout << ans << "\n";
    return 0;
}
