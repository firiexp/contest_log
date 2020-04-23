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

template <typename T>
struct edge {
    int from, to;
    T cost;

    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

    explicit operator int() const {return to;}
};

class UnionFind {
    vector<int> uni;
    int n;
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
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<edge<int>> G;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        G.emplace_back(a-1, b-1, c);
    }
    int cnt = n;
    sort(G.begin(),G.end(), [](const edge<int> &a, const edge<int> &b) { return (a.cost < b.cost); });
    UnionFind uf(n);
    int ans = 0;
    for (auto &&e : G){
        if(cnt == k) break;
        if(uf.unite(e.from, e.to)) cnt--, ans += e.cost;
    }
    cout << ans << "\n";
    return 0;
}