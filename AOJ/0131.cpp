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

void solve() {
    auto v = make_v(10, 10, 0);
    auto ans = v;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> v[i][j];
        }
    }
    auto s = v;
    auto flip = [&](int y, int x)  {
        ans[y][x] ^= 1; v[y][x] ^= 1;
        if(y) v[y-1][x] ^= 1;
        if(x) v[y][x-1] ^= 1;
        if(y != 9) v[y+1][x] ^= 1;
        if(x != 9) v[y][x+1] ^= 1;
    };
    for (int i = 0; i < (1 << 10); ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                ans[j][k] = 0;
            }
        }
        v = s;
        for (int j = 0; j < 10; ++j) {
            if(i & (1 << j)) flip(0, j);
        }
        for (int j = 1; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                if(v[j-1][k]) flip(j, k);
            }
        }
        int ok = 1;
        for (int j = 0; j < 10; ++j) {
            if(v[9][j]) ok = 0;
        }
        if(ok){
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    printf(k ? " %d" : "%d", ans[j][k]);
                }
                puts("");
            }
            return;
        }
    }
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        solve();
    }
    return 0;
}