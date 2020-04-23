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

template <typename T>
struct edge {
    int to; T cost;

    edge(int to, T cost) : to(to), cost(cost) {}
};

template <typename T>
vector<T> dijkstra(int s,vector<vector<edge<T>> > &G){
    size_t n=G.size();
    using P = pair<T, int>;
    vector<T> d(n, INF<T>);
    priority_queue<P,vector<P>,greater<> > Q;
    d[s]=0;
    Q.emplace(d[s],s);
    while(!Q.empty()){
        T cost;
        int i;
        tie(cost, i) = Q.top(); Q.pop();
        if(d[i] < cost) continue;
        for (auto &&e : G[i]) {
            auto cost2 = cost + e.cost;
            if(d[e.to] <= cost2) continue;
            d[e.to] = cost2;
            Q.emplace(d[e.to], e.to);
        }
    }
    return d;
}


int main() {
    int n, m, p, a, b;
    while(cin >> n >> m >> p >> a >> b, n){
        a--; b--;
        vector<int> v(n);
        for (auto &&i : v) scanf("%d", &i);
        vector<vector<edge<double>>> G(m<<n);
        for (int i = 0; i < p; ++i) {
            int x, y; double z; cin >> x >> y >> z;
            x--; y--;
            for (int j = 0; j < (1<<n); ++j) {
                for (int k = 0; k < n; ++k) {
                    if(j & (1<<k)){
                        int to = j^(1<<k);
                        G[(x<<n)+j].emplace_back((y<<n)+to, z/v[k]);
                        G[(y<<n)+j].emplace_back((x<<n)+to, z/v[k]);
                    }
                }
            }
        }
        using P = pair<double, int>;
        vector<double> d(m<<n, INF<double>);
        priority_queue<P,vector<P>,greater<> > Q;
        d[((a+1)<<n)-1]=0;
        Q.emplace(0, ((a+1)<<n)-1);
        while(!Q.empty()){
            double cost;
            int i;
            tie(cost, i) = Q.top(); Q.pop();
            if(d[i] < cost) continue;
            for (auto &&e : G[i]) {
                auto cost2 = cost + e.cost;
                if(d[e.to] <= cost2) continue;
                d[e.to] = cost2;
                Q.emplace(d[e.to], e.to);
            }
        }
        double ans = INF<double>;
        for (int i = 0; i < (1<<n); ++i) {
            ans = min(ans, d[(b<<n)+i]);
        }
        if(ans >= INF<int>){
            puts("Impossible");
        }else {
            printf("%.10lf\n", ans);
        }
    }

    return 0;
}