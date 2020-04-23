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
    explicit UnionFind(int n) : n(n), uni(n, -1) {};
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
    bool same(int a, int b){ return root(a) == root(b); }
};

int main() {
    int n, m;
    while(cin >> n >> m, n){
        UnionFind uf(2*n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            uf.unite(u, n+v);
            uf.unite(v, n+u);
        }
        if(uf.same(0, n)){
            puts("0");
            continue;
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if(uf.same(0, i)) cnt++;
        }
        vector<int> ans;
        if(cnt%2 == 0) ans.emplace_back(cnt/2);
        if((n-cnt)%2 == 0) ans.emplace_back((n-cnt)/2);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        cout << ans.size() << "\n";
        for (auto &&i : ans) {
            cout << i << "\n";
        }
    }
    return 0;
}