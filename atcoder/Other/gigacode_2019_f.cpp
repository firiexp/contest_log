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
#include <cassert>

static const int MOD = 1000000007;
using ll = long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    ll h, w, n;
    cin >> h >> w >> n;
    assert(h <= 350 && w <= 350);
    auto v = make_v(h+1, w+1, 0);
    for (int i = 0; i < n; ++i) {
        int r, c;
        scanf("%d %d", &r, &c);
        v[r][c]++;
    }
    for (int i = 0; i <= h; ++i) {
        for (int j = 0; j < w; ++j) {
            v[i][j+1] += v[i][j];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j <= w; ++j) {
            v[i+1][j] += v[i][j];
        }
    }

    auto exists = [&](int h1, int w1, int h2, int w2){
        if(h1 < 0 || w1 < 0 || h2 > h || w2 > w) return true;
        return (v[h2][w2]-v[h2][w1]-v[h1][w2]+v[h1][w1]) > 0;
    };
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = i+1; j <= h; ++j) {
            int l = 0, r = 0;
            while(r < w){
                r++;
                if(!exists(i, r, j, r+1)) continue;
                while(!exists(i, l-1, j, l) || exists(i, l, j, r)) l++;
                if(r-l >= 1 && exists(i-1, l, i, r) && exists(j, l, j+1, r)) {
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}