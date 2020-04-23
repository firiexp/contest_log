#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <functional>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

class UnionFind {
    vector<int> uni;
    int n;
public:
    explicit UnionFind(int n) : uni(static_cast<u32>(n), -1) , n(n){};

    int root(int a) {
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
    int n, k, l;
    cin >> n >> k >> l;
    UnionFind u1(n), u2(n);
    for (int i = 0; i < k; ++i) {
        int p, q;
        scanf("%d%d", &p, &q);
        u1.unite(p-1, q-1);
    }
    for (int j = 0; j < l; ++j) {
        int r, s;
        scanf("%d%d", &r, &s);
        u2.unite(r-1, s-1);
    }
    using P = pair<int, int>;
    vector<P> v;
    map<P, int> p;
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        v.emplace_back(make_pair(u1.root(i), u2.root(i)));
        p[make_pair(u1.root(i), u2.root(i))]++;
    }
    for (int i = 0; i < n; ++i) {
        if(i) cout << " ";
        cout << p[v[i]];
    }
    cout << "\n";
    return 0;
}
