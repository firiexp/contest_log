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
    int n, m;
    cin >> n >> m;
    UnionFind uni(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        uni.unite(a-1, b-1);
    }
    map<int, int> map1;
    for (int i = 0; i < n; ++i) {
        map1[uni.root(i)]++;
    }
    cout << map1.size()-1 << "\n";
    return 0;
}
