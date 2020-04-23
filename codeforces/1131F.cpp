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

struct QuickFind {
    int n;
    vector<int> roots;
    vector<vector<int>> v;
    explicit QuickFind(int n) : n(n) {
        v.resize(n);
        for (int i = 0; i < n; ++i) v[i].emplace_back(i);
        roots.resize(n);
        iota(roots.begin(),roots.end(), 0);
    }

    int root(int a){ return roots[a]; }
    size_t size(int a){ return v[a].size(); }
    bool unite(int a, int b){
        if(same(a, b)) return false;
        a = roots[a], b = roots[b];
        if(size(a) < size(b)) swap(a, b);
        for (auto &&i : v[b]) {
            v[a].emplace_back(i);
            roots[i] = a;
        }
        v[b].clear();
        v[b].shrink_to_fit();
        return true;
    }
    bool same(int a, int b){ return roots[a] == roots[b]; }
    const vector<int>& components(int x){ return v[roots[x]];}
};

int main() {
    int n;
    cin >> n;
    QuickFind uf(n);
    for (int i = 0; i < n-1; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--; r--;
        uf.unite(l, r);
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if(uf.root(i) == i){
            for (auto &&j : uf.components(i)) {
                ans.emplace_back(j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]+1);
    }
    return 0;
}