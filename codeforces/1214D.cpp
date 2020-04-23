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

template<class T, bool directed>
class Dinic {
    void bfs(int s){
        fill(level.begin(),level.end(), -1);
        queue<int> Q;
        level[s] = 0;
        Q.emplace(s);
        while(!Q.empty()){
            int v = Q.front(); Q.pop();
            for (auto &&e : G[v]){
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v] + 1;
                    Q.emplace(e.to);
                }
            }
        }
    }

    T dfs(int v, int t, T f){
        if(v == t) return f;
        for(int &i = iter[v]; i < G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]){
                T d = dfs(e.to, t, min(f,  e.cap));
                if(d == 0) continue;
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }
public:
    struct edge {
        int to{}; T cap; int rev{};
        edge() = default;
        edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}
    };

    vector<vector<edge>> G;
    vector<int> level, iter;
    Dinic() = default;
    explicit Dinic(int n) : G(n), level(n), iter(n) {}

    void add_edge(int from, int to, int cap){
        G[from].emplace_back(to, cap, G[to].size());
        G[to].emplace_back(from, directed ? 0 : cap,  G[from].size()-1);
    }


    T flow(int s, int t, T lim = INF<T>){
        T ret = 0;
        while(true) {
            bfs(s);
            if(level[t] < 0 || lim == 0) break;
            fill(iter.begin(),iter.end(), 0);
            while(true){
                T f = dfs(s, t, lim);
                if(f == 0) break;
                ret += f;
                lim -= f;
            }
        }
        return ret;
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n+2, vector<int>(m+2, 0));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            v[i+1][j+1] = (s[j] == '.');
        }
    }
    auto f = [&](int i, int j){ return i*m+j; };
    Dinic<int, true> G(n*m*2);
    array<int, 2> dx = {1, 0}, dy = {0, 1};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            G.add_edge(f(i, j), f(i, j)+n*m, 1);
            if(!v[i+1][j+1]) continue;
            for (int k = 0; k < 2; ++k) {
                if(v[i+1+dy[k]][j+1+dx[k]]){
                    G.add_edge(f(i, j)+n*m, f(i+dy[k], j+dx[k]), 1);
                }
            }
        }
    }
    cout << G.flow(n*m, n*m-1) << "\n";
    return 0;
}