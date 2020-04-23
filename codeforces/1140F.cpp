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

class UndoableUnionFind {
    stack<pair<int, int>> hist;
    vector<pair<int, int>> dp;
    stack<pair<int , pair<int, int>>> hist2;
    stack<int> hist3;
public:
    ll val = 0;
    vector<int> uni;
    explicit UndoableUnionFind(int sz) : uni(sz, -1),  val(0) {
        dp.resize(sz);
        for (int i = 0; i < sz/2; ++i) {
            dp[i] = {1, 0};
            dp[sz/2+i] = {0, 1};
        }
    }

    int root(int a){
        if(uni[a] < 0) return a;
        return root(uni[a]);
    }

    bool unite(int a, int b){
        a = root(a), b = root(b);
        hist.emplace(a, uni[a]);
        hist.emplace(b, uni[b]);
        hist2.emplace(a, dp[a]);
        hist2.emplace(b, dp[b]);
        hist3.emplace(a != b);
        if(a == b) return false;
        if(uni[a] > uni[b]) swap(a, b);
        val += (ll)dp[a].first*dp[b].second+(ll)dp[b].first*dp[a].second;
        uni[a] += uni[b];
        uni[b] = a;

        dp[a].first += dp[b].first; dp[a].second += dp[b].second;
        dp[b].first = dp[b].second = 0;
        return true;
    }

    int size(int i){ return -uni[root(i)]; }

    void undo(){
        uni[hist.top().first] = hist.top().second;
        hist.pop();
        uni[hist.top().first] = hist.top().second;
        hist.pop();
        auto a = hist2.top(); hist2.pop();
        auto b = hist2.top(); hist2.pop();
        dp[a.first] = a.second;
        dp[b.first] = b.second;
        if(hist3.top()) val -= (ll)a.second.first*b.second.second+(ll)a.second.second*b.second.first;
        hist3.pop();
    }
};



class OfflineDynamicConnectivity {
    int n;
    vector<vector<pair<int, int>>> seg;
    vector<pair<pair<int, int>, pair<int, int>>> pend;
    map<pair<int, int>, int> cnt, appear;
    void add(int a, int b, const pair<int ,int> &e){
        for (int l = a+sz, r = b+sz; l < r; l >>= 1, r >>= 1) {
            if(l&1) seg[l++].emplace_back(e);
            if(r&1) seg[--r].emplace_back(e);
        }
    }
public:
    int sz;
    UndoableUnionFind uf;
    OfflineDynamicConnectivity(int n, int q) : uf(n), n(n){
        sz = 1;
        while(sz < q) sz <<= 1;
        seg.resize(2*sz);
    }

    void insert(int t, int a, int b){
        auto e = minmax(a, b);
        if(cnt[e]++ == 0) appear[e] = t;
    }

    void erase(int t, int a, int b){
        auto e = minmax(a, b);
        if(--cnt[e] == 0) pend.emplace_back(make_pair(appear[e], t), e);
    }

    void build(){
        for (auto &&i : cnt) {
            if(!i.second) continue;
            pend.emplace_back(make_pair(appear[i.first], sz), i.first);
        }
        for (auto &&i : pend) {
            add(i.first.first, i.first.second, i.second);
        }
    }

    template<typename F>
    void run(const F &f, int k = 1){
        for (auto &&i : seg[k]) uf.unite(i.first, i.second);
        if(k < sz){
            run(f, (k << 1) | 0);
            run(f, (k << 1) | 1);
        }else {
            f(k-sz);
        }
        for (auto &&i : seg[k]) uf.undo();
    }
};

int main() {
    int q;
    cin >> q;
    const int M = 300000;
    OfflineDynamicConnectivity G(2*M, q);
    set<pair<int, int>> S;
    for (int i = 0; i < q; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--;
        if(S.count({x, y})){
            S.erase({x, y});
            G.erase(i, x, M+y);
        }else {
            S.emplace(x, y);
            G.insert(i, x, M+y);
        }
    }
    vector<ll> ans(G.sz);
    G.build();
    auto f = [&](int x){ ans[x] = G.uf.val; };
    G.run<decltype(f)>(f);
    for (int i = 0; i < q; ++i) {
        if(i) printf(" ");
        printf("%lld", ans[i]);
    }
    puts("");
    return 0;
}