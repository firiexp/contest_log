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

vector<ll> dp;
int k;
struct QuickFind {
    int n;
    vector<int> roots;
    vector<vector<int>> v;
    explicit QuickFind(int n) : n(n) {
        v.resize(n);
        for (int i = 0; i < n; ++i) v[i].emplace_back(i);
        roots.resize(n);
        iota(roots.begin(),roots.end(), 0);
    }

    int root(int a){ return roots[a]; }
    size_t size(int a){ return v[a].size(); }
    bool unite(int a, int b){
        if(same(a, b)) return false;
        a = roots[a], b = roots[b];
        if(size(a) < size(b)) swap(a, b);
        for (auto &&i : v[b]) {
            v[a].emplace_back(i);
            roots[i] = a;
        }
        dp[a] += dp[b];
        v[b].clear();
        v[b].shrink_to_fit();
        return true;
    }
    bool same(int a, int b){ return roots[a] == roots[b]; }
    const vector<int>& components(int x){ return v[roots[x]];}
};




int main() {
    int n;
    cin >> n >> k;
    QuickFind uf(2*k);
    dp.resize(2*k);
    for (int i = 0; i < k; ++i) {
        dp[i] = 0;
        dp[i+k] = 1;
    }
    string s;
    cin >> s;
    vector<vector<int>> v(n);
    for (int i = 0; i < k; ++i) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < x; ++j) {
            int y;
            scanf("%d", &y);
            v[y-1].emplace_back(i);
        }
    }
    vector<int> w(2*k);
    for (int i = 0; i < k; ++i) {
        w[i] = 1;
    }
    auto inv = [&](int x){
        if(x >= k) return x-k;
        else return x+k;
    };
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i].empty()){

        }else if(v[i].size() == 1){
            int p = uf.root(v[i][0]);
            if(s[i] == '0') { // fix to 1
                if(!w[inv(p)]){
                    ans -= dp[p]; ans += dp[inv(p)];
                    w[p] = 0; w[inv(p)] = 1;
                }
                dp[p] = k+1;
            } else{ // fix to 0
                if(!w[p]){
                    ans -= dp[inv(p)]; ans += dp[p];
                    w[inv(p)] = 0; w[p] = 1;
                }
                dp[inv(p)] = k+1;
            }
        }else {
            int p = uf.root(v[i][0]), q = uf.root(v[i][1]);
            if(s[i] == '0'){ // xor = 1
                if(!uf.same(p, inv(q))){
                    if(w[p]) ans -= dp[p];
                    else ans -= dp[inv(p)];
                    if(w[q]) ans -= dp[q];
                    else ans -= dp[inv(q)];
                    uf.unite(p, inv(q));
                    uf.unite(inv(p), q);
                    p = uf.root(v[i][0]), q = uf.root(v[i][1]);
                    if(dp[p] < dp[q]){
                        ans += dp[p];
                        w[p] = 1; w[inv(p)] = 0;
                    }else {
                        ans += dp[q];
                        w[q] = 1; w[inv(q)] = 0;
                    }
                }
            } else {
                if(!uf.same(p, q)){
                    if(w[p]) ans -= dp[p];
                    else ans -= dp[inv(p)];
                    if(w[q]) ans -= dp[q];
                    else ans -= dp[inv(q)];
                    uf.unite(p, q);
                    uf.unite(inv(p), inv(q));
                    p = uf.root(v[i][0]), q = uf.root(v[i][1]);
                    if(dp[p] < dp[inv(p)]){
                        ans += dp[p];
                        w[p] = 1; w[inv(p)] = 0;
                    }else {
                        ans += dp[inv(p)];
                        w[inv(p)] = 1; w[p] = 0;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}