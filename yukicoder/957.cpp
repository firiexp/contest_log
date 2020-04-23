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

    void add_edge(int from, int to, T cap){
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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int h, w;
    cin >> h >> w;
    Dinic<ll, true> flow(h+w+2);
    auto v = make_v(h, w, 0LL);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf("%lld", &v[i][j]);
        }
    }
    vector<ll> r(h), c(w);
    for (auto &&i : r) scanf("%lld", &i);
    for (auto &&k : c) scanf("%lld", &k);
    ll ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += r[i];
        flow.add_edge(0, i+1, 0);
        flow.add_edge(i+1, h+w+1, r[i]);
    }
    for (int i = 0; i < w; ++i) {
        ans += c[i];
        flow.add_edge(0, h+i+1, 0);
        flow.add_edge(h+i+1, h+w+1, c[i]);
    }
    for (int i = 0; i < h; ++i) {
        flow.add_edge(0, i+1, accumulate(v[i].begin(),v[i].end(), 0LL));
        for (int j = 0; j < w; ++j) {
            flow.add_edge(i+1, h+j+1, v[i][j]);
        }
    }
    cout << ans-flow.flow(0, h+w+1) << "\n";
    return 0;
}