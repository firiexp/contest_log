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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int ans = 0;
    int x = m-1-min(k, m-1);
    for (int l = 0; l <= min(k, m - 1); ++l) {
        int r = min(k, m-1) - l;
        int val = INF<int>;
        for (int l2 = l; l2 <= x+l; ++l2) {
            int r2 = r + x+l-l2;
            val = min(val, max(v[l2], v[n-r2-1]));
        }
        ans = max(ans, val);
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}