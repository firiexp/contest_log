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
    int n, b;
    cin >> n >> b;
    vector<int> xs(n), ys(n), ps(n);
    for (int i = 0; i < n; ++i) {
        cin >> xs[i] >> ys[i] >> ps[i];
    }
    auto zx = xs, zy = ys;
    sort(zx.begin(), zx.end());
    zx.erase(unique(zx.begin(), zx.end()), zx.end());
    sort(zy.begin(), zy.end());
    zy.erase(unique(zy.begin(), zy.end()), zy.end());
    auto v = make_v(zy.size()+1, zx.size()+1, 0);
    auto v2 = v;
    auto fx = [&zx](int x){ return lower_bound(zx.begin(),zx.end(), x) - zx.begin(); };
    auto fy = [&zy](int y){ return lower_bound(zy.begin(),zy.end(), y) - zy.begin(); };
    for (int i = 0; i < n; ++i) {
        v[fy(ys[i])+1][fx(xs[i])+1] += ps[i];
        v2[fy(ys[i])+1][fx(xs[i])+1]++;
    }
    for (int i = 0; i < zy.size(); ++i) {
        for (int j = 0; j < zx.size()+1; ++j) {
            v[i+1][j] += v[i][j];
            v2[i+1][j] += v2[i][j];
        }
    }
    for (int i = 0; i < zy.size()+1; ++i) {
        for (int j = 0; j < zx.size(); ++j) {
            v[i][j+1] += v[i][j];
            v2[i][j+1] += v2[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < zy.size(); ++i) {
        for (int j = i+1; j <= zy.size(); ++j) {
            int l = 0, r = 0;
            while(r < zx.size()){
                r++;
                while(l < r && v[j][r]-v[j][l]-v[i][r]+v[i][l] > b){
                    l++;
                }
                ans = max(ans, v2[j][r]-v2[j][l]-v2[i][r]+v2[i][l]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}