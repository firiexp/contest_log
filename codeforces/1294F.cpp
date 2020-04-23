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

using P = pair<int, int>;
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
            dpl[i].assign(G[i].size()+1, {P{0, i}, P{-1, -1}, P{-1, -1}});
            dpr[i].assign(G[i].size()+1, {P{0, i}, P{-1, -1}, P{-1, -1}});
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

array<P, 6> X{};
struct M {
    using T = array<P, 3>;
    using U = int;
    static T f(T a, T b) {
        X = {a[0], a[1], a[2], b[0], b[1], b[2]};
        inplace_merge(X.begin(), X.begin()+3, X.end(), greater<>());
        return {X[0], X[1], X[2]};
    }
    static T g(T a, U b) {
        auto x = *max_element(a.begin(),a.end());
        return {P{x.first+b, x.second}, P{0, -1}, P{0, -1}};
    }
    static T e() { return {P{0, -1}, P{0, -1}, P{0, -1}}; }
};

int main() {
    int n;
    cin >> n;
    ReRooting<M> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G.add_edge(a, b, 1);
    }
    int ans = 0, ans1 = 0, ans2 = 0, ans3 = 0;
    auto x = G.solve();
    for (int i = 0; i < n; ++i) {
        if(G.G[i].size() == 2){
            auto l = x[i][0], r = x[i][1];
            if(ans < l.first+r.first) {
                ans = l.first+r.first;
                ans1 = i; ans2 = l.second; ans3 = r.second;
            }
        }else if(G.G[i].size() >= 3){
            if(ans < x[i][0].first+x[i][1].first+x[i][2].first){
                ans = x[i][0].first+x[i][1].first+x[i][2].first;
                ans1 = x[i][0].second; ans2 = x[i][1].second; ans3 = x[i][2].second;
            }
        }
    }
    printf("%d\n%d %d %d\n", ans, ans1+1, ans2+1, ans3+1);
    return 0;
}