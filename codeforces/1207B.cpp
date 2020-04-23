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
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &v[i][j]);
        }
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i+1 < n; ++i) {
        for (int j = 0; j+1 < m; ++j) {
            if(v[i][j] != 0 && v[i+1][j] != 0 && v[i][j+1] != 0 && v[i+1][j+1] != 0){
                v[i][j] = 2; v[i+1][j] = 2; v[i][j+1] = 2; v[i+1][j+1] = 2;
                ans.emplace_back(i+1, j+1);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(v[i][j] == 1){
                puts("-1");
                return 0;
            }
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}