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
    cin >> n >> m;
    vector<map<int, int>> v(m);
    for (int i = 0; i < m; ++i) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            int y;
            cin >> y;
            v[i][y-1]++;
        }
    }
    vector<int> u(m);
    for (auto &&l : u) scanf("%d", &l);
    int ans = 0;
    for (int i = 0; i < (1<<n); ++i) {
        vector<int> cnt(m);
        for (int j = 0; j < n; ++j) {
            if(!(i & (1<<j))) continue;
            for (int k = 0; k < m; ++k) {
                if(v[k][j]) cnt[k] ^= 1;
            }
        }
        if(u == cnt) ans++;
    }
    cout << ans << "\n";
    return 0;
}