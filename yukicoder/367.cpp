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
    vector<string> v(h);
    int sy = 0, sx = 0, gy = 0, gx = 0;
    for (int i = 0; i < h; ++i) {
        cin >> v[i];
        for (int j = 0; j < w; ++j) {
            if(v[i][j] == 'S') sy = i, sx = j;
            if(v[i][j] == 'G') gy = i, gx = j;
        }
    }
    array<int, 8> dy1{1, 2, 2, 1, -1, -2, -2, -1},
                  dx1{-2, -1, 1, 2, 2, 1, -1, -2};
    array<int, 4> dy2{1, 1, -1, -1}, dx2{1, -1, 1, -1};
    queue<tuple<int, int, int>> Q;
    Q.emplace(0, sy, sx);
    auto d = make_v(2, h, w, INF<int>);
    auto in = [&](int y, int x){
        return 0 <= y && y < h && 0 <= x && x < w;
    };
    d[0][sy][sx] = 0;
    while(!Q.empty()){
        int a, y, x; tie(a, y, x) = Q.front(); Q.pop();
        if(!a){
            for (int k = 0; k < 8; ++k) {
                if(in(y+dy1[k], x+dx1[k]) && d[a^(v[y+dy1[k]][x+dx1[k]] == 'R')][y+dy1[k]][x+dx1[k]] == INF<int>){
                    int b = a^(v[y+dy1[k]][x+dx1[k]] == 'R');
                    d[b][y+dy1[k]][x+dx1[k]] = d[a][y][x] + 1;
                    Q.emplace(b, y+dy1[k], x+dx1[k]);
                }
            }
        }else {
            for (int k = 0; k < 4; ++k) {
                if(in(y+dy2[k], x+dx2[k]) && d[a^(v[y+dy2[k]][x+dx2[k]] == 'R')][y+dy2[k]][x+dx2[k]] == INF<int>){
                    int b = a^(v[y+dy2[k]][x+dx2[k]] == 'R');
                    d[b][y+dy2[k]][x+dx2[k]] = d[a][y][x] + 1;
                    Q.emplace(b, y+dy2[k], x+dx2[k]);
                }
            }
        }
    }
    int ans = min(d[0][gy][gx], d[1][gy][gx]);
    if(ans == INF<int>) puts("-1");
    else cout << ans << "\n";
    return 0;
}