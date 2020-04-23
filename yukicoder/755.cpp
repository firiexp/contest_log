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

template <class T>
vector<T> make_v(size_t size, const T& init){ return vector<T>(size, init); }

template<class... Ts>
auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }



int main() {
    int n, m;
    cin >> n >> m;
    auto v = make_v(m+1, m+1, 0LL);
    auto ans = make_v(m+1, m+1, 0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i+1][j+1];
        }
    }
    for (int i = 0; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            v[i][j] += v[i][j-1];
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
            v[i][j] += v[i-1][j];
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = i; k <= m; ++k) {
                for (int l = j; l <= m; ++l) {
                    if(v[k][l]-v[i-1][l]-v[k][j-1]+v[i-1][j-1] == 0){
                        ans[i-1][j-1]++; ans[i-1][l]--; ans[k][j-1]--; ans[k][l]++;
                    }
                }
            }
        }
    }
    for (int i = 0; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            ans[i][j] += ans[i][j-1];
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
            ans[i][j] += ans[i-1][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        cout << ans[a-1][b-1] << "\n";
    }
    return 0;
}
