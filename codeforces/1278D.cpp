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
    int n;
    cin >> n;
    UnionFind uf(n);
    vector<pair<int, int>> v(2*n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--;
        v[x] = {y, i};
        v[y] = {x, i};
    }
    set<int> s;
    int cnt = 0;
    for (int i = 0; i < 2*n; ++i) {
        if(!s.count(v[i].first)) s.emplace(i);
        else {
            for (auto x = --s.end(); *x != v[i].first && cnt < n; --x) {
                uf.unite(v[i].second, v[*x].second);
                cnt++;
            }
            s.erase(v[i].first);
        }
        if(cnt == n) break;
    }
    puts(cnt == n-1 && uf.size() == 1 ? "YES" : "NO");
    return 0;
}