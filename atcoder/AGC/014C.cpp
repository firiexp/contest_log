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

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }


int main() {
    int h, w, k;
    cin >> h >> w >> k;
    auto v = make_v(h, w, 0);
    pair<int, int> S;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            v[i][j] = (s[j] == '#');
            if(s[j] == 'S') S = make_pair(i, j);
        }
    }
    int dx[] = {1, -1, 0, 0, 0}, dy[] = {0, 0, 1, -1, 0};
    if(k == 1){
        int ans = INF<int>;
        for (int i = 0; i < 5; ++i) {
            int y = S.first+dy[i], x = S.second+dx[i];
            if(v[y][x]) continue;
            chmin(ans, min({y, h-1-y, x, w-1-x}));
        }
        cout << ans+1 << "\n";
        return 0;
    }
    auto grid = make_v(h, w, make_pair(INF<int>, 0));
    grid[S.first][S.second] = make_pair(0, 0);
    queue<pair<int, int>> q;
    auto in = [&](int y, int x){ return 0 <= y && y < h && 0 <= x && x < w;};
    q.push(S);
    while(!q.empty()){
        int yy, xx; tie(yy, xx) = q.front(); q.pop();
        int a, b; tie(a, b) = grid[yy][xx];
        for (int i = 0; i < 4; ++i) {
            int y = yy+dy[i], x = xx+dx[i];
            if(!in(y, x)) continue;
            pair<int, int> to = make_pair(max(a+1, (b+v[y][x]+k-1)/k*k), b+v[y][x]);
            if(to < grid[y][x]){
                grid[y][x] = to;
                q.emplace(y, x);
            }
        }
    }
    int ans = INF<int>;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if((i == 0 || i == h-1) || (j == 0 || j == w-1)){
                chmin(ans, grid[i][j].first);
            }
        }
    }
    cout << ans/k+1 << "\n";
    return 0;
}

