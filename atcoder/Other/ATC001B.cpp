#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

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

    int size(int a){
        return -uni[root(a)];
    }
};


int main() {
    int n, q;
    cin >> n >> q;
    UnionFind u(n);
    for (int i = 0; i < q; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(a) cout << ((u.root(b) == u.root(c)) ? "Yes" : "No") << "\n";
        else u.unite(b, c);
    }
    return 0;
}
