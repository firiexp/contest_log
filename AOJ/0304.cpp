#include <iostream>
#include <algorithm>
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

template <typename T>
struct edge {
    int from, to;
    T cost;

    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

    explicit operator int() const {return to;}
};

template <typename T>
vector<T> bellman_ford(int s, int N,vector<edge<T> > &G){
    vector<T> dist(N, INF<T>);
    vector<bool> negative(N);
    dist[s] = 0;
    for (int i = 0; i < N; ++i) {
        for (auto &&e : G) {
            if(dist[e.from] == INF<T>) continue;
            if(dist[e.to] > dist[e.from]+ e.cost){
                dist[e.to] = dist[e.from]+ e.cost;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (auto &&e : G) {
            if(dist[e.from] == INF<T>) continue;
            if(dist[e.to] > dist[e.from] + e.cost){
                dist[e.to] = dist[e.from] + e.cost;
                negative[e.to] = true;
            }
            if(negative[e.from]) negative[e.to] = true;
        }
    }
    for (int i = 0; i < N; ++i) {
        if(negative[i]) dist[i] = -INF<T>;
    }
    return dist;
}


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}


int main() {
    int n, c;
    cin >> n >> c;
    using P = array<int, 4>;
    vector<edge<int>> G;
    vector<P> p;
    for (int i = 0; i < c; ++i) {
        string s;
        cin >> s;
        string a, b;
        auto cur = s.begin();
        int u = 0, v = 0, w = 0;
        while(isdigit(*cur)) u = (u*10+*(cur++)-'0');
        while(!isdigit(*cur)) a += *(cur++);
        while(isdigit(*cur)) v = (v*10+*(cur++)-'0');
        while(!isdigit(*cur)) b += *(cur++);
        while(isdigit(*cur)) w = (w*10+*(cur++)-'0');
        u--; v--;
        if(a == "*"){
            p.emplace_back(P{u, v, w, b == "+"});
        }else {
            if(a == ">=") swap(u, v);
            if(b == "+"){
                G.emplace_back(v, u, -w);
            }else {
                G.emplace_back(u, v, w);
                G.emplace_back(v, u, 0);
            }
        }
    }
    int ans = -1, cnt = 0;
    for (int i = 0; i < (1 << p.size()); ++i) {
        for (int j = 0; j < p.size(); ++j) {
            if(i & (1 << j)) swap(p[j][0], p[j][1]);
            if(p[j][3]){
                G.emplace_back(p[j][1], p[j][0], -p[j][2]);
                cnt++;
            }else {
                G.emplace_back(p[j][0], p[j][1], p[j][2]);
                G.emplace_back(p[j][1], p[j][0], 0);
                cnt += 2;
            }
            if(i & (1 << j)) swap(p[j][0], p[j][1]);
        }
        auto dist = bellman_ford(0, n, G);
        int l = *min_element(dist.begin(),dist.end());
        int r = *max_element(dist.begin(),dist.end());
        if(l >= 0) ans = max(ans, r);
        for (int j = 0; j < cnt; ++j) G.pop_back();
        cnt = 0;
    }
    if(ans >= INF<int>) puts("inf");
    else cout << ans << "\n";
    return 0;
}