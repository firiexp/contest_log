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
    int n, m;
    array<int, 4> dx{-1, 1, 0, 0}, dy{0, 0, -1, 1};
    while(cin >> m >> n, n){
        auto G = make_v(n+4, m+4, -1);
        for (int i = 1; i < n+3; ++i) {
            for (int j = 1; j < m+3; ++j) {
                G[i][j] = 1;
            }
        }
        int gx = 0, gy = 0;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                G[i+2][j+2] = (s[j] != '#');
                if(s[j] == '&'){
                    gy = i+2, gx = j+2;
                }
            }
        }
        auto dp = make_v(n+4, m+4, -1);
        dp[1][1] = 0;
        deque<pair<int, int>> Q;
        Q.emplace_back(1, 1);
        while(!Q.empty()){
            int y, x; tie(y, x) = Q.front(); Q.pop_front();
            for (int k = 0; k < 4; ++k) {
                if(!~G[y+dy[k]][x+dx[k]] || ~dp[y+dy[k]][x+dx[k]]) continue;
                if(G[y][x] == G[y+dy[k]][x+dx[k]]){
                    dp[y+dy[k]][x+dx[k]] = dp[y][x];
                    Q.emplace_front(y+dy[k], x+dx[k]);
                }else {
                    dp[y+dy[k]][x+dx[k]] = dp[y][x]+1;
                    Q.emplace_back(y+dy[k], x+dx[k]);
                }
            }
        }
        cout << dp[gy][gx]/2 << "\n";
    }
    return 0;
}