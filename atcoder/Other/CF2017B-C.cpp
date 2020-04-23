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
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;


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
    ll n, m;
    cin >> n >> m;
    UnionFind uni(2*n);
    for (int i = 0; i < m; ++i) {
        u32 a, b;
        scanf("%d %d", &a, &b);
        uni.unite(a-1, b-1+n);
        uni.unite(a-1+n, b-1);
    }

    if(uni.root(0) == uni.root(n)){
        cout << n*(n-1)/2 - m << "\n";
    }else {
        int c = 1;
        for (int i = 1; i < n; ++i) {
            if(uni.root(0) == uni.root(i)) c++;
        }
        cout << (n-c) * c - m << "\n";
    }
    return 0;
}
