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

bool IsKadomatsu(int a, int b, int c){
    if(!min({a, b, c})) return true;
    if(a == b || b == c || c == a) return false;
    return max({a, b, c}) == b || min({a, b, c}) == b;
}

int main() {
    int w, h;
    cin >> w >> h;
    auto grid = make_v(h+2, w+2, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i+1][j+1];
        }
    }
    auto dp = make_v(h, w, 10, 10, INF<int>);
    queue<tuple<int, int, int, int>> Q;
    dp[0][0][0][grid[1][1]] = 0;
    Q.emplace(0, 0, 0, grid[1][1]);
    array<int, 4> dy{-1, 1, 0, 0}, dx{0, 0, -1, 1};
    while(!Q.empty()){
        int s, t, a, b; tie(s, t, a, b) = Q.front(); Q.pop();
        for (int i = 0; i < 4; ++i) {
            int c = grid[s+1+dy[i]][t+1+dx[i]];
            if(!c) continue;
            if(dp[s][t][a][b]+1 >= dp[s+dy[i]][t+dx[i]][b][c]) continue;
            if(IsKadomatsu(a, b, c)){
                dp[s+dy[i]][t+dx[i]][b][c] = dp[s][t][a][b]+1;
                Q.emplace(s+dy[i], t+dx[i], b, c);
            }
        }
    }
    int ans = INF<int>;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            ans = min(ans, dp[h-1][w-1][i][j]);
        }
    }
    cout << (ans < INF<int> ? ans : -1) << "\n";
    return 0;
}