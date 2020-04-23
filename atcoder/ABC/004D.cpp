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

template<typename F, typename C>
struct PrimalDual {
    struct edge {
        int to; F cap; C cost; int rev;
        edge() = default;
        edge(int to, F cap, C cost, int rev):to(to), cap(cap), cost(cost), rev(rev) {};
    };
    vector<vector<edge>> G;
    vector<C> potential, min_cost;
    vector<int> prevv, preve;

    explicit PrimalDual(int n) : G(n), potential(n), min_cost(n), prevv(n), preve(n) {}

    void add_edge(int u, int v, F cap, C cost){
        G[u].emplace_back(v, cap, cost, G[v].size());
        G[v].emplace_back(u, 0, -cost, G[u].size()-1);
    }

    struct P{
        C first; int second;
        P(C first,int second):first(first),second(second){}
        bool operator<(const P&a) const{return a.first<first;}
    };
    void dijkstra(int s){

        priority_queue<P> Q;
        fill(min_cost.begin(),min_cost.end(), INF<C>);
        min_cost[s] = 0;
        Q.emplace(0, s);
        while(!Q.empty()){
            P p = Q.top(); Q.pop();
            int v = p.second;
            if(min_cost[v] < p.first) continue;
            for(int i = 0; i < G[v].size(); ++i){
                edge &e=G[v][i];
                if(e.cap==0) continue;
                if(min_cost[v]+e.cost+potential[v]-potential[e.to] < min_cost[e.to]){
                    min_cost[e.to] = min_cost[v]+e.cost+potential[v]-potential[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    Q.emplace(min_cost[e.to], e.to);
                }
            }
        }
    }

    C flow(int s, int t, F fl, int &ok){
        C res = 0;
        fill(potential.begin(),potential.end(), 0);
        while(fl > 0){
            dijkstra(s);
            if(min_cost[t] == INF<C>){
                ok = 0;
                return res;
            }
            for (int i = 0; i < potential.size(); ++i) {
                if(min_cost[i] < INF<C>) potential[i] += min_cost[i];
            }

            F d = fl;
            for(int v = t; v != s; v = prevv[v]){
                d = min(d, G[prevv[v]][preve[v]].cap);
            }
            fl -= d;
            res += potential[t]*d;
            for(int v = t; v != s; v = prevv[v]){
                G[prevv[v]][preve[v]].cap -= d;
                G[v][G[prevv[v]][preve[v]].rev].cap += d;
            }
        }
        ok = 1;
        return res;
    }
};


int main() {
    int r, g, b;
    cin >> r >> g >> b;
    PrimalDual<int, int> flow(1206);
    flow.add_edge(0, 1, r, 0);
    flow.add_edge(0, 2, g, 0);
    flow.add_edge(0, 3, b, 0);
    for (int i = -600; i <= 600; ++i) {
        flow.add_edge(1, i+604, 1, abs(i+100));
        flow.add_edge(2, i+604, 1, abs(i));
        flow.add_edge(3, i+604, 1, abs(i-100));
        flow.add_edge(i+604, 1205, 1, 0);
    }
    int ok = 0;
    cout << flow.flow(0, 1205, r+g+b, ok) << "\n";
    return 0;
}