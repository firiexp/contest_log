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

template<typename M>
class ReRooting {
public:
    using T = typename M::T;
    using U = typename M::U;
    struct Node {
        int to, rev;
        U val;
        Node(int u, int v, U val) : to(u), rev(v), val(val) {};
    };
    int n;
    vector<vector<Node>> G;
    vector<vector<T>> dpl, dpr;
    vector<int> l, r;

    explicit ReRooting(int n) : n(n), G(n), dpl(n), dpr(n), l(n), r(n) {};

    void add_edge(int u, int v, const U &x) {
        G[u].emplace_back(v, G[v].size(), x);
        G[v].emplace_back(u, G[u].size()-1, x);
    }
    void add_edge(int u, int v, const U &x, const U &y) {
        G[u].emplace_back(v, G[v].size(), x);
        G[v].emplace_back(u, G[u].size()-1, y);
    }

    T dfs(int i, int par){
        while(l[i] != par && l[i] < G[i].size()){
            auto &e = G[i][l[i]];
            dpl[i][l[i] + 1] = M::f(dpl[i][l[i]], M::g(dfs(e.to, e.rev), e.val));
            ++l[i];
        }
        while(r[i] != par && r[i] >= 0){
            auto &e = G[i][r[i]];
            dpr[i][r[i]] = M::f(dpr[i][r[i] + 1], M::g(dfs(e.to, e.rev), e.val));
            --r[i];
        }
        if(par < 0) return dpr[i].front();
        return M::f(dpl[i][par], dpr[i][par+1]);
    }

    vector<T> solve(){
        for (int i = 0; i < n; ++i) {
            dpl[i].assign(G[i].size()+1, M::e());
            dpr[i].assign(G[i].size()+1, M::e());
            l[i] = 0;
            r[i] = (int)G[i].size() - 1;
        }
        vector<T> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = dfs(i, -1);
        }
        return ans;
    }
};

struct M {
    using T = int;
    using U = int;
    static T f(T a, T b) { return max(a, b); }
    static T g(T a, U b) {
        return a+b;
    }
    static T e() { return 0; }
};


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
    int n, k;
    cin >> n >> k;
    ReRooting<M> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--; b--;
        G.add_edge(a, b, c);
    }
    auto v = G.solve();
    int A = min_element(v.begin(),v.end()) - v.begin();
    vector<int> dist(n);
    auto bfs = [&](int i, int par, int X, auto &&f) -> pair<int, int> {
        pair<int, int> state = {0, 0};
        for (auto &&j : G.G[i]) {
            if(j.to != par){
                auto ret = f(j.to, i, X, f);
                if(ret.first >= 2 || ret.first == -1 || (ret.first == 1 && state.first == 2)){
                    return {-1, -1};
                }else if(ret.first == 1 || dist[j.to]+j.val > X){
                    state = {state.first+1, state.second+ret.second+1};
                }
                dist[i] = max(dist[i], dist[j.to]+j.val);
            }
        }
        return state.first > 2 ? make_pair(-1, -1) : state;
    };
    int ng = -1, ok = INF<int>;
    while(ok-ng > 1){
        int mid = (ok+ng)/2;
        auto ret = bfs(A, -1, mid, bfs);
        if(ret.first == -1 || ret.second >= k){
            ng = mid;
        }else {
            ok = mid;
        }
    }
    cout << ok << "\n";
    return 0;
}