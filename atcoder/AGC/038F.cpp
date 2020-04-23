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

class UnionFind {
    int n;
    vector<int> uni;
    int cnt;
public:
    explicit UnionFind(int n) : uni(static_cast<u32>(n), -1) , n(n), cnt(n) {};

    int root(int a){
        if (uni[a] < 0) return a;
        else return (uni[a] = root(uni[a]));
    }

    bool unite(int a, int b) {
        a = root(a);
        b = root(b);
        if(a == b) return false;
        if(uni[a] > uni[b]) swap(a, b);
        uni[a] += uni[b];
        uni[b] = a;
        cnt--;
        return true;
    }

    int size(int i){ return -uni[root(i)]; }
    int size(){ return cnt; }
    bool same(int a, int b) { return root(a) == root(b); }
};

int main() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (auto &&i : p) scanf("%d", &i);
    for (auto &&i : q) scanf("%d", &i);

    UnionFind ufA(n), ufB(n);
    for (int i = 0; i < n; ++i) {
        ufA.unite(i, p[i]);
        ufB.unite(i, q[i]);
    }
    Dinic<int, true> G(2*n+2);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(i == p[i] && i == q[i]) {
            continue;
        }
        ans++;
        if(i == q[i]){
            G.add_edge(ufA.root(i)+1, 2*n+1, 1);
        }else if(i == p[i]){
            G.add_edge(0, ufB.root(i)+n+1, 1);
        }else if(p[i] == q[i]){
            G.add_edge(ufA.root(i)+1, ufB.root(i)+n+1, 1);
            G.add_edge(ufB.root(i)+n+1,ufA.root(i)+1,  1);
        }else {
            G.add_edge(ufA.root(i)+1, ufB.root(i)+n+1, 1);
        }
    }
    cout << ans - G.flow(0, G.G.size()-1) << "\n";
    return 0;
}