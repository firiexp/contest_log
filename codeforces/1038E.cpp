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

class UnionFind {
    int n;
    vector<int> uni;
    int forest_size;
public:
    explicit UnionFind(int n) : n(n), uni(static_cast<u32>(n), -1), forest_size(n) {};

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
        forest_size--;
        return true;
    }
    int size(){ return forest_size; }
    int size(int i){ return -uni[root(i)]; }
    bool same(int a, int b) { return root(a) == root(b); }
};

int main() {
    int n;
    cin >> n;
    vector<int> self(4);
    vector<int> xs{0, 0, 0, 1, 1, 2}, ys{1, 2, 3, 2, 3, 3},
    zs{-1, 0, 1, 2, 0, -1, 3, 4, 1, 3, -1, 5, 2, 4, 5, -1};
    vector<int> mn(6, INF<int>), S(6), cnt(6);
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &c, &b);
        a--; b--;
        if(a == b) self[a] += c;
        else {
            int z = zs[a+b*4];
            mn[z] = min(mn[z], c);
            S[z] += c; cnt[z]++;
        }
    }
    int ans = 0;
    for (int T = 0; T < (1 << 6); ++T) {
        int ok = 1;
        UnionFind uf(4);
        for (int j = 0; j < 6; ++j) {
            if((T & (1 << j)) && !cnt[j]) ok = 0;
            if(cnt[j]-((T >> j) & 1)) uf.unite(xs[j], ys[j]);
        }
        if(!ok) continue;
        vector<int> vals(4), deg(4);
        for (int j = 0; j < 6; ++j) {
            deg[xs[j]] += cnt[j]-((T >> j) & 1);
            deg[ys[j]] += cnt[j]-((T >> j) & 1);
            vals[uf.root(xs[j])] += S[j] - ((T >> j) & 1)*mn[j];
        }
        for (int j = 0; j < 4; ++j) vals[uf.root(j)] += self[j];

        for (int j = 0; j < 4; ++j) {
            if(uf.root(j) != j) continue;
            int x = 0;
            for (int k = 0; k < 4; ++k) {
                if(uf.root(k) == j) x += deg[k]&1;
            }
            if(x <= 2){
                ans = max(ans, vals[j]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}