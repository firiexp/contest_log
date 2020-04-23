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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, m, w;
    cin >> n >> m >> w;
    UnionFind uf(n);
    vector<int> ws(n), vs(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &ws[i], &vs[i]);
    }
    for (int i = 0; i < m; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        uf.unite(a-1, b-1);
    }
    vector<int> wws(n), vvs(n);
    for (int i = 0; i < n; ++i) {
        wws[uf.root(i)] += ws[i];
        vvs[uf.root(i)] += vs[i];
    }
    auto dp = make_v(n+1, w+1, -INF<ll>);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= w; ++j) {
            chmax(dp[i+1][j], dp[i][j]);
        }
        for (int j = 0; j+wws[i] <= w; ++j) {
            chmax(dp[i+1][j+wws[i]], dp[i][j]+vvs[i]);
        }
    }
    cout << *max_element(dp.back().begin(),dp.back().end()) << "\n";
    return 0;
}