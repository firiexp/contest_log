#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> ans(n, 0);
    for (int i = 0; i < m; ++i) {
        int u = 0;
        for (int j = 0; j < n; ++j) {
            int k;
            cin >> k;
            if(k == v[i]) ans[j]++;
            else u++;
        }
        ans[v[i]-1] += u;
    }
    for (int i = 0; i < n; ++i) printf("%d\n", ans[i]);

    return 0;
}
