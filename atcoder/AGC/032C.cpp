#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


class UnionFind {
    int n;
public:
    vector<int> uni;
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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> e(n);
    vector<pair<int, int>> G;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a-1]++; e[b-1]++;
        G.emplace_back(a-1, b-1);
    }
    int c = 0, p = 0;
    for (int i = 0; i < n; ++i) {
        if(e[i]&1){
            puts("No");
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(e[i] >= 6){
            puts("Yes");
            return 0;
        }else if(e[i] == 4) {
            c++;
            p = i;
        }
    }
    if(c >= 3){
        puts("Yes");
        return 0;
    }else if(c <= 1){
        puts("No");
        return 0;
    }
    UnionFind uf(n);
    for (int i = 0; i < m; ++i) {
        if(G[i].first != p && G[i].second != p){
            uf.unite(G[i].first, G[i].second);
        }
    }
    int sz = -uf.uni[uf.root(p == 0 ? 1 : 0)];
    puts(sz == n-1 ? "No" : "Yes");
    return 0;
}
