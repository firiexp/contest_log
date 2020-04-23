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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a(m), b(n);
    for (auto &&i : a) scanf("%d", &i);
    for (auto &&j : b) scanf("%d", &j);
    vector<vector<int>> v(n, vector<int> (m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &v[i][j]);
            if(v[i][j]) v[i][j] = min(b[i], a[j]);
            if(j) printf(" ");
            printf("%d", v[i][j]);
        }
        puts("");
    }

    return 0;
}
