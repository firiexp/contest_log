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
            edge e = G[v][i];
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

    bool add_edge(int from, int to, int cap){
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
    int n, h, w;
    cin >> n >> h >> w;
    Dinic<ll, true> G();

    return 0;
}