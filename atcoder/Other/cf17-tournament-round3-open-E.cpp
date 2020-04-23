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

class UnionFind {
    int n;
    vector<int> uni;
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

    int size(int i){ return -uni[root(i)]; }
    bool same(int a, int b) { return root(a) == root(b); }
};

int main() {
    int n;
    cin >> n;
    vector<array<int, 3>> v(n-1);
    for (int i = 0; i < n-1; ++i) {
        scanf("%d %d %d", &v[i][1], &v[i][2], &v[i][0]);
        v[i][1]--; v[i][2]--;
    }
    UnionFind uf(n);
    vector<int> par(n);
    for (int i = 0; i < n; ++i) {
        par[i] = i;
    }
    sort(v.begin(),v.end(), greater<>());
    vector<vector<int>> G(2*n-1);
    vector<ll> dp(2*n-1, 1), dq(2*n-1, 0);
    for (int i = 0; i < n-1; ++i) {
        int x = par[uf.root(v[i][1])], y = par[uf.root(v[i][2])];
        par[uf.root(v[i][1])] = par[uf.root(v[i][2])] = n+i;
        uf.unite(v[i][1], v[i][2]);
        dp[n+i] = dp[x]+dp[y];
        dq[y] += dp[x]*v[i][0], dq[x] += dp[y]*v[i][0];
        G[n+i].emplace_back(y);
        G[n+i].emplace_back(x);
    }
    for (int j = 2*n-2; j >= n; --j) {
        for (auto &&i : G[j]) {
            dq[i] += dq[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%lli\n", dq[i]);
    }
    return 0;
}