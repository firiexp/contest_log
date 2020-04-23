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
    using P = pair<int, int>;
    vector<pair<int, int>> v(n);
    vector<int> z;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v[i].first, &v[i].second);
        z.emplace_back(v[i].first);
        z.emplace_back(v[i].second);
    }
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    int m = z.size();
    auto f = [&z](int x){return lower_bound(z.begin(),z.end(), x) - z.begin(); };
    UnionFind uf(m);
    for (int i = 0; i < n; ++i) {
        uf.unite(f(v[i].first), f(v[i].second));
    }
    vector<int> a(m);
    for (int i = 0; i < n; ++i) {
        a[uf.root(f(v[i].first))]++;
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if(a[i]) ans += min(a[i], uf.size(i));
    }
    cout << ans << "\n";
    return 0;
}