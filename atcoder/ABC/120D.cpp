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
    ll n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &v[i].first, &v[i].second);
    }
    vector<ll> ans(m);
    reverse(v.begin(), v.end());
    ans[0] = n*(n-1)/2;
    UnionFind uf(n);
    for (int i = 0; i < m - 1; ++i) {
        ll k = ans[i];
        int a, b; tie(a, b) = v[i];
        a--; b--;
        if(uf.root(a) != uf.root(b)){
            k -= uf.uni[uf.root(a)]*uf.uni[uf.root(b)];
            uf.unite(a, b);
        }
        ans[i+1] = k;
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[m-i-1] << "\n";
    }
    return 0;
}
