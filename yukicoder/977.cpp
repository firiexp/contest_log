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
#include <cassert>

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
    vector<int> as, bs;
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        uf.unite(a, b);
        as.emplace_back(a);
        bs.emplace_back(b);
    }
    if(uf.size() == 1){
        puts("Bob");
        return 0;
    }else if(uf.size() >= 3){
        puts("Alice");
        return 0;
    }

    vector<int> v(n);
    for (int i = 0; i < n-1; ++i) {
        v[as[i]]++;
        v[bs[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        if(uf.size(i) != 1 && v[i] < 2){
            puts("Alice");
            return 0;
        }
    }
    puts("Bob");
    return 0;
}