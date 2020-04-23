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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<vector<int>> G(n+1);
    UnionFind uf(n);
    for (int i = 0; i < n; ++i) {
        if(v[i]) uf.unite(i, v[i]+i);
    }
    vector<int> dp(n, -1);
    for (int i = 0; i < n; ++i) {
        if(!v[i]){
            dp[uf.root(i)] = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(dp[uf.root(i)] == -1) dp[uf.root(i)] = n;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 6 && i+j < n; ++j) {
            G[i].emplace_back(dp[uf.root(i+j)]);
        }
    }
    queue<int> Q;
    Q.push(0);
    vector<int> dis(n+1, MOD);
    dis[0] = 0;
    while(!Q.empty()){
        int i = Q.front(); Q.pop();
        for (auto &&j : G[i]) {
            if(dis[i]+1 < dis[j]){
                Q.emplace(j);
                dis[j] = dis[i]+1;
            }
        }
    }
    cout << dis[n-1] << "\n";
    return 0;
}