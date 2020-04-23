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
using ll = int64_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> T clamp(T x, T a, T b) { return max(min(x, b), a); }

int main() {
    int n, aaa, aaaa;
    cin >> n >> aaa >> aaaa;
    vector<array<int, 4>> v(n);
    for (auto &&i : v) scanf("%d %d %d %d", &i[0], &i[1], &i[2], &i[3]);
    int m = 0, ans = 0;
    for (auto &&i : v) {
        auto g = make_v(i[2]-i[0]+2, i[3]-i[1]+2, 0);
        for (auto &&j : v) {
            int a = clamp(j[0], i[0], i[2]+1)-i[0], p = clamp(j[1], i[1], i[3]+1)-i[1],
                b = clamp(j[2]+1, i[0], i[2]+1)-i[0], q = clamp(j[3]+1, i[1], i[3]+1)-i[1];
            g[a][p]++; g[a][q]--; g[b][p]--; g[b][q]++;
        }
        for (int j = 1; j < g.size(); ++j) {
            for (int k = 0; k < g[0].size(); ++k) {
                g[j][k] += g[j-1][k];
            }
        }
        for (int j = 0; j < g.size(); ++j) {
            for (int k = 1; k < g[0].size(); ++k) {
                g[j][k] += g[j][k-1];
            }
        }
        for (int j = 0; j < g.size(); ++j) {
            for (int k = 0; k < g[0].size(); ++k) {
                if(m == g[j][k]) ans++;
                else if(m < g[j][k]) ans = 1, m = g[j][k];
            }
        }
    }
    cout << m << "\n" << ans/m << "\n";
    return 0;
}
