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
using ll = int64_t;
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
    int h, w;
    cin >> h >> w;
    auto v = make_v(h+2, w+2, -1);
    v[0][0] = v[h+1][0] = v[0][w+1] = v[h+1][w+1] = 0;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            v[i+1][j+1] = (s[j] == '1');
        }
    }
    long double ans = 1e15;
    for (int i = 0; i <= h+1; ++i) {
        for (int j = 0; j <= w+1; ++j) {
            if(v[i][j] == -1){
                long double x = 0;
                for (int k = 1; k <= h; ++k) {
                    for (int l = 1; l <= w; ++l) {
                        if(v[k][l] == 1){
                            x += hypot(k-i, l-j);
                        }
                    }
                }
                ans = min(ans, x);
            }
        }
    }
    cout << setprecision(15) << ans << "\n";
    return 0;
}
