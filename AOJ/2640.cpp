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
    int n, m;
    cin >> n >> m;
    auto dp = make_v(n+2, m+2, 4, 8, INF<int>);
    auto G = make_v(n+2, m+2, 0);
    auto visited = make_v(n+2, m+2, 0);
    int gy = 0, gx = 0;

    using tup = array<int, 4>;
    deque<tup> Q;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            G[i+1][j+1] = (s[j] != '#');
            if(s[j] == 'G') gy = i+1, gx = j+1;
            if(s[j] == '^') Q.emplace_front(tup{i+1, j+1, 0, 2});
            if(s[j] == '>') Q.emplace_front(tup{i+1, j+1, 1, 4});
            if(s[j] == 'v') Q.emplace_front(tup{i+1, j+1, 2, 6});
            if(s[j] == '<') Q.emplace_front(tup{i+1, j+1, 3, 0});
        }
    }
    {
        auto p = Q.front();
        dp[p[0]][p[1]][p[2]][p[3]] = 1;
    }

    array<int, 4> dy{-1, 0, 1, 0}, dx{0, 1, 0, -1};
    array<int, 8> di{-1, -1, 0, 1, 1, 1, 0, -1}, dj{0, 1, 1, 1, 0, -1, -1, -1};
    while(!Q.empty()){
        auto p = Q.front(); Q.pop_front();
        visited[p[0]][p[1]] = 1;
        if(gy == p[0] && gx == p[1]){
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    ans += visited[i+1][j+1];
                }
            }
            cout << ans << "\n";
            return 0;
        }

        int relative = (p[3]-2*p[2]+16)%8;
        if(G[p[0]+dy[p[2]]][p[1]+dx[p[2]]] && relative != 3){
            if(dp[p[0]][p[1]][p[2]][p[3]] + 1 <
                    dp[p[0]+dy[p[2]]][p[1]+dx[p[2]]][p[2]][(p[3]+1)%8]){
                dp[p[0]+dy[p[2]]][p[1]+dx[p[2]]][p[2]][(p[3]+1)%8] =
                        dp[p[0]][p[1]][p[2]][p[3]] + 1;
                Q.emplace_back(tup{p[0]+dy[p[2]], p[1]+dx[p[2]], p[2], (p[3]+1)%8});
            }
        }
        if(relative <= 1){
            if(dp[p[0]][p[1]][p[2]][p[3]] < dp[p[0]][p[1]][(p[2]+3)%4][p[3]]){
                dp[p[0]][p[1]][(p[2]+3)%4][p[3]] = dp[p[0]][p[1]][p[2]][p[3]];
                Q.emplace_front(tup{p[0], p[1], (p[2]+3)%4, p[3]});
            }
        }else {
            if(dp[p[0]][p[1]][p[2]][p[3]] < dp[p[0]][p[1]][(p[2]+1)%4][p[3]]){
                dp[p[0]][p[1]][(p[2]+1)%4][p[3]] = dp[p[0]][p[1]][p[2]][p[3]];
                Q.emplace_front(tup{p[0], p[1], (p[2]+1)%4, p[3]});
            }
        }
        if(relative != 0){
            int to = (p[3]+7)%8;
            if(!G[p[0]+di[to]][p[1]+dj[to]]){
                if(dp[p[0]][p[1]][p[2]][p[3]] < dp[p[0]][p[1]][p[2]][to]){
                    dp[p[0]][p[1]][p[2]][to] = dp[p[0]][p[1]][p[2]][p[3]];
                    Q.emplace_front(tup{p[0], p[1], p[2], to});
                }
            }
        }
        if(relative != 3){
            int to = (p[3]+1)%8;
            if(!G[p[0]+di[to]][p[1]+dj[to]]){
                if(dp[p[0]][p[1]][p[2]][p[3]] < dp[p[0]][p[1]][p[2]][to]){
                    dp[p[0]][p[1]][p[2]][to] = dp[p[0]][p[1]][p[2]][p[3]];
                    Q.emplace_front(tup{p[0], p[1], p[2], to});
                }
            }
        }
        if(relative == 0){
            int to = (p[3]+2)%8;
            if(!G[p[0]+di[to]][p[1]+dj[to]]){
                if(dp[p[0]][p[1]][p[2]][p[3]] < dp[p[0]][p[1]][p[2]][to]){
                    dp[p[0]][p[1]][p[2]][to] = dp[p[0]][p[1]][p[2]][p[3]];
                    Q.emplace_front(tup{p[0], p[1], p[2], to});
                }
            }
        }
        if(relative == 2){
            int to = (p[3]+6)%8;
            if(!G[p[0]+di[to]][p[1]+dj[to]]){
                if(dp[p[0]][p[1]][p[2]][p[3]] < dp[p[0]][p[1]][p[2]][to]){
                    dp[p[0]][p[1]][p[2]][to] = dp[p[0]][p[1]][p[2]][p[3]];
                    Q.emplace_front(tup{p[0], p[1], p[2], to});
                }
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}