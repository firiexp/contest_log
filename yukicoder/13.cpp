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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

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
    int w, h;
    cin >> w >> h;
    auto v = make_v(h+2, w+2, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf("%d", &v[i+1][j+1]);
        }
    }
    UnionFind uf(h*w);
    vector<int> dp(h*w);
    auto f = [&](int i, int j){ return i*w+j; };
    array<int, 2> dy {1, 0}, dx {0, 1};
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            for (int k = 0; k < 2; ++k) {
                if(v[i][j] == v[i+dy[k]][j+dx[k]]){
                    if(!uf.unite(f(i-1, j-1), f(i+dy[k]-1, j+dx[k]-1))){
                        puts("possible");
                        return 0;
                    }
                }
            }
        }
    }
    puts("impossible");
    return 0;
}