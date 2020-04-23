#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T, class F>
struct segment_tree{
    int sz;
    vector<T> seg;
    const F f;
    const T M;
    segment_tree(int n, const F f, const T &M) : f(f), M(M) {
        sz = 1;
        while(sz < n) sz <<= 1;
        seg.assign(2*sz, M);
    }

    void set(int k, const T &x){
        seg[k + sz] = x;
    }

    void build(){
        for (int i = sz-1; i > 0; --i) seg[i] = f(seg[2*i], seg[2*i+1]);
    }

    void update(int k, const T &x){ // 0-indexed
        k += sz;
        seg[k] = x;
        while (k >>= 1){
            seg[k] = f(seg[2*k], seg[2*k+1]);
        }
    }

    T query(int a, int b){ // 0-indexed
        T l = M, r = M;
        for(a += sz, b += sz; a < b; a >>=1, b>>=1){
            if(a & 1) l = f(l, seg[a++]);
            if(b & 1) r = f(seg[--b], r);
        }
        return f(l, r);
    }

    T operator[](const int &k) const { // 0-indexed
        return seg[k + sz];
    }
};
/*
Use this template
auto f = [](int a, int b){ return min(a, b); };
segment_tree<int, decltype(f)> seg(n, f, INF<int>);
 */

template <typename T>
struct edge {
    int from, to;
    T cost;

    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

    explicit operator int() const {return to;}
};

class UnionFind {
    vector<int> uni;
    int n;
public:
    explicit UnionFind(int n) : uni(static_cast<u32>(n), -1) , n(n){};

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
        return true;
    }
};

template< typename T >
T kruskal(vector<edge<T>> &G, int V)
{
    sort(begin(G), end(G), [](const edge< T > &a, const edge< T > &b) { return (a.cost < b.cost); });
    UnionFind tree(V);
    T ret = 0;
    for(auto &e : G) {
        if(tree.unite(e.from, e.to)) ret += e.cost;
    }
    return (ret);
}

int main() {
    ll n, d;
    cin >> n >> d;
    using P = pair<ll, int>;
    vector<P> v(n);
    for (int i = 0; i < n; ++i) {
        ll x; scanf("%lld", &x);
        v[i] = make_pair(x, i);
    }
    auto u = v;
    sort(v.begin(), v.end());
    auto f = [](P a, P b){ return a.first > b.first ? b : a; };
    segment_tree<P, decltype(f)> seg1(n+1, f, make_pair(INF<ll>, -1));
    segment_tree<P, decltype(f)> seg2(n+1, f, make_pair(INF<ll>, -1));
    vector<edge<ll>> G;
    for (int i = 0; i < n; ++i) {
        int id; ll  cost; tie(cost, id) = v[i];
        P a = seg1.query(id, n+1), b = seg2.query(0, id+1);
        if(a.second != -1) G.emplace_back(id, a.second, u[id].first+u[a.second].first+abs(id-a.second)*d);
        if(b.second != -1) G.emplace_back(id, b.second, u[id].first+u[b.second].first+abs(id-b.second)*d);
        seg1.update(id, make_pair(cost+d*id, id));
        seg2.update(id, make_pair(cost+d*(n-1-id), id));
    }
    cout << kruskal(G, n) << "\n";

    return 0;
}
