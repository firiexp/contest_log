#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }


int main() {
    int n, m;
    cin >> n >> m;
    auto v = make_v(n, n, 0);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        v[a][b] = v[b][a] = 1;
    }
    if(3 >= n){
        puts("0");
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                for (int l = k+1; l < n; ++l) {
                    int a = v[i][j] + v[i][k] + v[i][l],
                    b = v[j][i] + v[j][k] + v[j][l],
                    c = v[k][i] + v[k][j] + v[k][l],
                    d = v[l][i] + v[l][j] + v[l][k];
                    if(a == 2 && b == 2 && c == 2 && d == 2){
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
