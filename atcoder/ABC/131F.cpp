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
   UnionFind uf(100001);
   vector<vector<int>> v(100001), u(100001);
   
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].emplace_back(y);
        u[y].emplace_back(x);
    }
    vector<int> dp(100001);
    for (int i = 1; i <= 100000; ++i) {
        for (int j = 0; j+1 < u[i].size(); ++j) {
            uf.unite(u[i][j], u[i][j+1]);
        }
    }
    for (int i = 1; i <= 100000; ++i) {
        int j = uf.root(i);
        if(i != j){
            for (auto &&k : v[i]) {
                v[j].emplace_back(k);
            }
        }
    }
    ll ans = -n;
    for (int i = 1; i <= 100000; ++i) {
        if(i == uf.root(i)){
            sort(v[i].begin(), v[i].end());
            v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
            ans += (ll)v[i].size()*uf.size(i);
        }
    }
    cout << ans << "\n";

   return 0;
}