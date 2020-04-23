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
    vector<pair<int, int>> A(n), B(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i].first);
        A[i].second = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &B[i].first);
        B[i].second = i;
    }

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    UnionFind uf(n);
    int ok = 0;
    for (int i = 0; i < n; ++i) {
        uf.unite(A[i].second, B[i].second);
        if(i && A[i].first <= B[i-1].first){
            ok = 1;
        }
        if(A[i].first > B[i].first){
            puts("No");
            return 0;
        }
    }
    puts(uf.size() == 1 && !ok ? "No" : "Yes");
    return 0;
}