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
    vector<ll> xs(n), ys(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &xs[i], &ys[i]);
    }
    UnionFind uf(n);
    vector<array<ll, 3>> v(n*n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            v[i*n+j] = {(xs[i]-xs[j])*(xs[i]-xs[j])+(ys[i]-ys[j])*(ys[i]-ys[j]), i, j};
        }
    }
    ll ans = 0;
    sort(v.begin(),v.end());
    for (int i = n; i < n*n; ++i) {
        if(uf.same(0, n-1)) break;
        if(uf.unite(v[i][1], v[i][2])){
            ans = max(ans, v[i][0]);
        }
    }
    ll ng = 0, ok = 142000000;
    while(ok-ng > 1){
        ll mid = (ok+ng)/2;
        (mid*mid*100 >= ans ? ok : ng) = mid;
    }
    cout << ok*10 << "\n";
    return 0;
}