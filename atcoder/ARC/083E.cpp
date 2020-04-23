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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a;
        scanf("%d", &a);
        G[a-1].emplace_back(i+1);
    }
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);

    deque<int> Q;
    {
        vector<int> num(n);
        {
            stack<int> s;
            int cnt = 0;
            vector<int> visited(n, 0);
            s.emplace(0);
            while(!s.empty()){
                int a = s.top(); s.pop();
                visited[a]++;
                num[a] = cnt++;
                Q.emplace_front(a);
                for (auto &&i : G[a]) {
                    if(!visited[i]) s.emplace(i);
                }
            }
        }
    }
    auto dp = make_v(n, 2, 2, INF<int>);
    while(!Q.empty()){
        int x = Q.front(); Q.pop_front();
        if(G[x].empty()) {
            dp[x][0][0] = dp[x][1][1] = 0;
            dp[x][0][1] = dp[x][1][0] = v[x];
            continue;
        }
        vector<array<int, 5001>> knap(G[x].size()+1);
        for (int c = 0; c < 2; ++c) {
            for (auto &&k : knap) {
                fill(k.begin(), k.end(), INF<int>);
            }
            knap[0][0] = 0;
            for (int i = 0; i < G[x].size(); ++i) {
                int y = G[x][i];
                for (int j = 0; j <= v[x]; ++j) {
                    if(knap[i][j] == INF<int>) continue;
                    for (int k = 0; k < 2; ++k) {
                        int id = dp[y][k][c], val = dp[y][k][c^1];
                        if(j+id <= v[x]){
                            chmin(knap[i+1][j+id], knap[i][j]+val);
                        }
                    }
                }
            }
            for (int j = 0; j <= v[x]; ++j) {
                if(knap[G[x].size()][j] != INF<int>){
                    chmin(dp[x][c][c^1], knap[G[x].size()][j]);
                    dp[x][c][c] = v[x];
                }
            }
        }
    }
    if(dp[0][0][0] != INF<int> || dp[0][1][1] != INF<int>){
        puts("POSSIBLE");
    }else {
        puts("IMPOSSIBLE");
    }
    return 0;
}
