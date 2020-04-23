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

int main() {
    int h, w;
    cin >> h >> w;
    auto v = make_v(h+2, w+2, 0);
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            v[i+1][j+1] = (s[j] == '.');
        }
    }
    int ans = 0;
    array<int, 4> dy{-1, 1, 0, 0}, dx{0, 0, -1, 1};
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(!v[i+1][j+1]) continue;
            auto dist = make_v(h+2, w+2, INF<int>);
            queue<pair<int, int>> Q;
            Q.emplace(i+1, j+1);
            dist[i+1][j+1] = 0;
            while(!Q.empty()){
                int y, x; tie(y, x) = Q.front(); Q.pop();
                for (int k = 0; k < 4; ++k) {
                    if(!v[y+dy[k]][x+dx[k]]) continue;
                    if(dist[y+dy[k]][x+dx[k]] > dist[y][x]+1){
                        dist[y+dy[k]][x+dx[k]] = dist[y][x]+1;
                        Q.emplace(y+dy[k], x+dx[k]);
                    }
                }
            }
            for (int k = 0; k < h; ++k) {
                for (int l = 0; l < w; ++l) {
                    if(dist[k+1][l+1] != INF<int>){
                        ans = max(ans, dist[k+1][l+1]);
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}