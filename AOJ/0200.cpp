#include <iostream>
#include <algorithm>
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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, m;
    while(cin >> m >> n, n){
        vector<vector<int>> d1(n, vector<int>(n, INF<int>));
        for (int i = 0; i < n; ++i) d1[i][i] = 1;
        auto d2 = d1;
        for (int i = 0; i < m; ++i) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            a--; b--;
            chmin(d1[a][b], c); chmin(d1[b][a], c);
            chmin(d2[a][b], d); chmin(d2[b][a], d);
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    chmin(d1[i][j], d1[i][k]+d1[k][j]);
                }
            }
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    chmin(d2[i][j], d2[i][k]+d2[k][j]);
                }
            }
        }
        int q;
        cin >> q;
        for (int i = 0; i < q; ++i) {
            int x, y, r;
            cin >> x >> y >> r;
            if(r == 0){
                cout << d1[x-1][y-1] << "\n";
            }else {
                cout << d2[x-1][y-1] << "\n";
            }
        }
    }
    return 0;
}