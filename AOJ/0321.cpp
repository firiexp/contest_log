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

class UnionFind {
    int n;
    vector<int> uni;
    int forest_size;
public:
    vector<int> dp;
    explicit UnionFind(int n) : n(n), uni(static_cast<u32>(n), -1), forest_size(n), dp(n) {};

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
        dp[a] += dp[b];
        uni[b] = a;
        forest_size--;
        return true;
    }
    int size(){ return forest_size; }
    int size(int i){ return -uni[root(i)]; }
    bool same(int a, int b) { return root(a) == root(b); }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    UnionFind uf(n+m);
    for (int i = 0; i < m; ++i) {
        uf.dp[i+n]++;
    }
    for (int i = 0; i < k; ++i) {
        int a, x, y;
        scanf("%d %d %d", &a, &x, &y);
        x--; y--;
        if(a == 1){
            uf.unite(x, y);
        }else {
            uf.unite(x, y+n);
        }
        if(uf.dp[uf.root(x)] >= 2){
            printf("%d\n", i+1);
            return 0;
        }
    }
    puts("0");
    return 0;
}