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

    int size(int i){ return -uni[root(i)]; }
    bool same(int a, int b) { return root(a) == root(b); }
};

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> v(h+2, vector<int> (w+2, 0));
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf("%d", &v[i+1][j+1]);
            ans += v[i+1][j+1];
        }
    }
    UnionFind uf(h*w);
    auto f = [&](int a, int b){ return (a-1)*w+b-1; };
    array<int, 4> dx{1, -1, 0, 0}, dy{0, 0, -1, 1};
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            for (int k = 0; k < 4; ++k) {
                if(v[i][j] && v[i+dy[k]][j+dx[k]]){
                    ans -= uf.unite(f(i, j), f(i+dy[k], j+dx[k]));
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}