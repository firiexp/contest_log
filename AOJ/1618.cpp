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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int h, w;
    while(cin >> h >> w, h){
        auto v = make_v(h+2, w+2, 0);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> v[i+1][j+1];
            }
        }
        int ans = 0;
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                for (int k = i+2; k <= h; ++k) {
                    for (int l = j+2; l <= w; ++l) {
                        int m1 = v[i][j], m2 = 0;
                        for (int m = i; m <= k; ++m) {
                            for (int n = j; n <= l; ++n) {
                                if(m == i || m == k || n == j || n == l){
                                    m1 = min(m1, v[m][n]);
                                }else {
                                    m2 = max(m2, v[m][n]);
                                }
                            }
                        }
                        if(m1 > m2) {
                            int sum = 0;
                            for (int m = i; m <= k; ++m) {
                                for (int n = j; n <= l; ++n) {
                                    if(m == i || m == k || n == j || n == l); else {
                                        sum += m1-v[m][n];
                                    }
                                }
                            }
                            ans = max(ans, sum);
                        }

                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}