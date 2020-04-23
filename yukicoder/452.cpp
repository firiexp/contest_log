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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, m;
    cin >> n >> m;
    auto v = make_v(m, 2*n+2, n, 0);
    int ans = INF<int>;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                scanf("%d", &v[i][j][k]);
                v[i][k+n][j] = v[i][j][k];
            }
        }
        for (int j = 0; j < n; ++j) {
            v[i][2*n][j] = v[i][j][j];
            v[i][2*n+1][j] = v[i][n-j-1][j];
        }
        for (int j = 0; j < 2*n+2; ++j) {
            sort(v[i][j].begin(),v[i][j].end());
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = i+1; j < m; ++j) {
            for (int k = 0; k < 2*n+2; ++k) {
                for (int l = 0; l < 2*n+2; ++l) {
                    int a = 0, b = 0, cnt = 0;
                    while(a < n || b < n){
                        cnt++;
                        if(a == n) b++;
                        else if(b == n) a++;
                        else if(v[i][k][a] == v[j][l][b]) a++, b++;
                        else if(v[i][k][a] < v[j][l][b]) a++;
                        else b++;
                    }
                    ans = min(ans, cnt);
                }
            }
        }
    }
    cout << max(1, ans-1) << "\n";
    return 0;
}