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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    auto v = make_v(n, m, 0);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            v[i][j] = (s[j] == '1');
        }
    }
    auto s = make_v(n+1, m+1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            s[i+1][j+1] = v[i][j];
        }
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < m+1; ++j)  s[i+1][j] += s[i][j];
    for (int i = 0; i < n+1; ++i) for (int j = 0; j < m; ++j)  s[i][j+1] += s[i][j];

    auto verw = make_v(n+1, m, 0);
    auto verh = make_v(n, m+1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m-1; ++j) {
            if(v[i][j] && v[i][j+1]) verw[i+1][j+1] = 1;
        }
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)  verw[i+1][j] += verw[i][j];
    for (int i = 0; i < n+1; ++i) for (int j = 0; j < m-1; ++j)  verw[i][j+1] += verw[i][j];
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < m; ++j) {
            if(v[i][j] && v[i+1][j]) verh[i+1][j+1] = 1;
        }
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)  verh[i][j+1] += verh[i][j];
    for (int i = 0; i < n-1; ++i) for (int j = 0; j < m+1; ++j)  verh[i+1][j] += verh[i][j];
    while(q--){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int ans = s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
        ans -= verh[x2-1][y2] - verh[x1-1][y2] - verh[x2-1][y1-1] + verh[x1-1][y1-1];
        ans -= verw[x2][y2-1] - verw[x1-1][y2-1] - verw[x2][y1-1] + verw[x1-1][y1-1];
        printf("%d\n", ans);
    }
    return 0;
}
