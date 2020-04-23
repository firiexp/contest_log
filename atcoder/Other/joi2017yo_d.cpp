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

template<class T> T INF = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i), i--;
    vector<vector<int>> cnt(m, vector<int>(n+1, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cnt[i][j+1] = cnt[i][j]+(v[j] != i);
        }
    }
    vector<int> dp1(1<<m), dp2(1<<m, INF<int>);
    for (int i = 0; i < (1 << m); ++i) {
        for (int j = 0; j < m; ++j) {
            if(i & (1 << j)){
                dp1[i] = dp1[i^(1<<j)] + n-cnt[j][n];
                break;
            }
        }
    }
    dp2[0] = 0;
    for (int i = 0; i < (1 << m); ++i) {
        for (int j = 0; j < m; ++j) {
            if(i & (1 << j)){
                dp2[i] = min(dp2[i], dp2[i^(1 << j)] + cnt[j][dp1[i]]-cnt[j][dp1[i-(1<<j)]]);
            }
        }
    }
    cout << dp2.back() << "\n";
    return 0;
}