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
    ll n;
    cin >> n;

    vector<ll> xs, ys;

    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        if(x != 0 || y != 0) xs.emplace_back(x), ys.emplace_back(y);
    }
    n = xs.size();
    ll ans = n*(n-1)*(n-2)/6;
    UnionFind uf(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(xs[i]*ys[j] == xs[j]*ys[i]){
                uf.unite(i, j);
            }
        }
    }
    ll ans2 = 0;
    for (int i = 0; i < n; ++i) {
        if(uf.root(i) == i){
            ll a = uf.size(i);
            ans -= a*(a-1)/2*(n-a);
            ans -= a*(a-1)*(a-2)/6;
            ll l = 0, r = 0;
            vector<int> ls, rs;
            for (int j = 0; j < n; ++j) {
                if(uf.root(i) == uf.root(j)) continue;
                if(xs[i]*ys[j] - xs[j]*ys[i] > 0) l++, ls.emplace_back(j);
                if(xs[i]*ys[j] - xs[j]*ys[i] < 0) r++, rs.emplace_back(j);
            }
            ans2 += l*(l-1)*a/2;
            ans2 += r*(r-1)*a/2;
        }
    }
    cout << ans-ans2/2 << "\n";
    return 0;
}