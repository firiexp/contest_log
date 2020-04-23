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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

int main() {
    int w, h;
    cin >> w >> h;
    auto v = make_v(h+2, w+2, -1);
    int sy, sx;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            v[i+1][j+1] = (s[j] == '.');
            if(v[i+1][j+1]) sy = i+1, sx = j+1;
        }
    }
    auto dis = make_v(h+2, w+2, INF<int>);
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
    stack<tuple<int, int, int>> s;
    s.emplace(sy, sx, 0);
    while(!s.empty()){
        int y, x, d; tie(y, x, d) = s.top(); s.pop();
        if(dis[y][x] < d) continue;
        dis[y][x] = d;
        for (int k = 0; k < 4; ++k) {
            int c = d+(v[y+dy[k]][x+dx[k]] == 0);
            if(v[y+dy[k]][x+dx[k]] != -1 && dis[y+dy[k]][x+dx[k]] > c) s.emplace(y+dy[k], x+dx[k], c);
        }
    }
    int ans = INF<int>;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if(dis[i][j] != 0 && v[i][j]) ans = min(ans, dis[i][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}
