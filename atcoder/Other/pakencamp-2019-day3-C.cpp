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

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &v[i][j]);
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = i+1; j < m; ++j) {
            ll val = 0;
            for (int k = 0; k < n; ++k) {
                val += max(v[k][i], v[k][j]);
            }
            ans = max(ans, val);
        }
    }
    cout << ans << "\n";
    return 0;
}