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
    int n;
    cin >> n;
    vector<vector<int>> v(n+1, vector<int>(n+1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &v[i+1][j+1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            v[i+1][j] += v[i][j];
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            v[i][j+1] += v[i][j];
        }
    }
    int ans = -INF<int>;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = i+1; k <= n; ++k) {
                for (int l = j+1; l <= n; ++l) {
                    ans = max(ans, v[k][l]-v[k][j]-v[i][l]+v[i][j]);
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}