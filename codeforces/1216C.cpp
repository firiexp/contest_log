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
    vector<int> xs1(3), ys1(3), xs2(3), ys2(3);
    vector<int> zx, zy;
    for (int i = 0; i < 3; ++i) {
        cin >> xs1[i] >> ys1[i] >> xs2[i] >> ys2[i];
        zx.emplace_back(xs1[i]);
        zx.emplace_back(xs2[i]);
        zy.emplace_back(ys1[i]);
        zy.emplace_back(ys2[i]);
    }
    sort(zx.begin(), zx.end());
    zx.erase(unique(zx.begin(), zx.end()), zx.end());
    sort(zy.begin(), zy.end());
    zy.erase(unique(zy.begin(), zy.end()), zy.end());
    auto fx = [&zx](int x){ return lower_bound(zx.begin(),zx.end(), x) - zx.begin(); };
    auto fy = [&zy](int y){ return lower_bound(zy.begin(),zy.end(), y) - zy.begin(); };
    auto v = make_v(zx.size()+1, zy.size()+1, 0);
    for (int i = 1; i < 3; ++i) {
        for (int x = fx(xs1[i]); x < fx(xs2[i]); ++x) {
            for (int y = fy(ys1[i]); y < fy(ys2[i]); ++y) {
                v[x][y] = 1;
            }
        }
    }
    int ok = 1;
    for (int x = fx(xs1[0]); x < fx(xs2[0]); ++x) {
        for (int y = fy(ys1[0]); y < fy(ys2[0]); ++y) {
            if(!v[x][y]) ok = 0;
        }
    }
    puts(ok ? "NO" : "YES");
    return 0;
}