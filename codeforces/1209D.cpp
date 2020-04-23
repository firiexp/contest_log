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
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<pair<int, int>> v;
    for (int i = 0; i < m; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        uf.unite(a-1, b-1);
        a--; b--;
        v.emplace_back(a, b);
    }
    int ans = 0;
    vector<int> u(n);
    for (int i = 0; i < n; ++i) {
        u[uf.root(i)]++;
    }
    for (int i = 0; i < n; ++i) {
        if(u[i]){
            ans += u[i]-1;
        }
    }
    cout << m-ans << "\n ";
    return 0;
}