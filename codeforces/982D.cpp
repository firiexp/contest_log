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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> ind(n);
    iota(ind.begin(),ind.end(), 0);
    sort(ind.begin(),ind.end(), [&](int x, int y){ return v[x] < v[y]; });
    int ans = v[ind.front()]+1, locs = 1;
    int cur = 0;
    vector<int> exist(n+2);
    int sz = 0;
    UnionFind uf(n);
    multiset<int> s;
    while(cur < n) {
        int curr = cur;
        while(curr < n && v[ind[cur]] == v[ind[curr]]){
            sz++;
            exist[ind[curr]+1] = 1;
            s.emplace(1);
            if(exist[ind[curr]]) {
                s.erase(s.find(uf.size(ind[curr])));
                s.erase(s.find(uf.size(ind[curr]-1)));
                uf.unite(ind[curr], ind[curr]-1);
                s.emplace(uf.size(ind[curr]));
                sz--;
            }
            if(exist[ind[curr]+2]) {
                s.erase(s.find(uf.size(ind[curr])));
                s.erase(s.find(uf.size(ind[curr]+1)));
                uf.unite(ind[curr], ind[curr]+1);
                s.emplace(uf.size(ind[curr]));
                sz--;
            }
            curr++;
        }
        if(locs < sz && *s.begin() == *(--s.end())){
            sz = locs;
            ans = v[ind[cur]]+1;
        }
        cur = curr;
    }
    cout << ans << "\n";
    return 0;
}