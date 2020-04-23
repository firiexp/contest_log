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

template<class T>
class Dinic {
    struct edge {
        int to{}, rev{};
        T cap;
        edge() = default;
        edge(int to, T cap, int rev):to(to), cap(cap), rev(rev) {}
    };
    int n{};
    vector<vector<edge>> G;
    vector<int> level, iter;
public:
    Dinic() = default;
    explicit Dinic(int sz): n(sz), G(n), level(n), iter(n){}
    void add_edge(int from, int to, T cap, bool directed){
        G[from].emplace_back(to, cap, G[to].size());
        G[to].emplace_back(from, directed?0:cap, G[from].size()-1);
    }

    void bfs(int s){
        fill(level.begin(), level.end(), -1);
        queue<int> Q;
        level[s] = 0;
        Q.emplace(s);
        while(!Q.empty()){
            int v = Q.front(); Q.pop();
            for (auto &&e : G[v]) {
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v]+1;
                    Q.emplace(e.to);
                }
            }
        }
    }

    T dfs(int v, int t, T f){
        if(v == t) return f;
        for (int &i = iter[v]; i < G[v].size(); ++i) {
            edge &e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]){
                T d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    T flow(int s, int t, T lim = INF<T>){
        T fl = 0;
        while(true){
            bfs(s);
            if(level[t] < 0 || lim == 0) return fl;
            fill(iter.begin(), iter.end(), 0);
            T f;
            while((f=dfs(s,t, lim))>0){
                fl += f;
                lim -= f;
            }
        }
    }

    bool back_edge(int s, int t, int from, int to){
        for (auto &&e : G[from]) {
            if(e.to == to) {
                if(e.cap == 0 && flow(from, to, 1) == 0){
                    flow(from, s, 1);
                    flow(t, to, 1);
                    return true;
                }
            }
        }
        return false;
    }

};

int main() {
    int h, w;
    cin >> h >> w;
    Dinic<int> flow(h+w+2);
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            if(s[j] == 'S'){
                flow.add_edge(0, i+1, INF<int>, true);
                flow.add_edge(0, h+j+1, INF<int>, true);
            }else if(s[j] == 'T'){
                flow.add_edge(i+1, h+w+1, INF<int>, true);
                flow.add_edge(h+j+1, h+w+1, INF<int>, true);
            }else if(s[j] == 'o'){
                flow.add_edge(i+1, h+j+1, 1, false);
            }
        }
    }
    int ans = flow.flow(0, h+w+1);
    cout << (ans >= MOD ? -1 : ans) << "\n";
    return 0;
}
