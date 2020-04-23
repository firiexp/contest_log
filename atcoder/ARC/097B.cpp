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
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    UnionFind g(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g.unite(x-1, y-1);
    }
    map<int, vector<int>> map1;
    for (int i = 0; i < n; ++i) {
        map1[g.root(v[i]-1)].emplace_back(i+1);
        map1[g.root(v[i]-1)].emplace_back(v[i]);
    }
    int ans = 0;
    for (auto &&j : map1) {
        sort(j.second.begin(), j.second.end());
        for (int i = 0; i < j.second.size()-1; ++i) {
            if(j.second[i] == j.second[i+1]) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
