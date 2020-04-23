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
    int n, m;
    cin >> n >> m;
    UnionFind G(n), B(2*n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G.unite(a, b);
        B.unite(a, b+n);
        B.unite(a+n, b);
    }
    ll a = 0, b = 0, c = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(G.root(i) == i){
            if(G.size(i) == 1) c++;
            else if(B.same(i, i+n)) b++;
            else a++;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(G.root(i) == i){
            if(G.size(i) == 1) {
                ans += n;
            }else if(B.same(i, i+n)){
                ans += c*G.size(i)+a+b;
            }else {
                ans += c*G.size(i)+2*a+b;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}