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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> v(h, vector<int>(w, -1));
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            if(s[j] == '#') v[i][j] = 0;
        }
    }
    vector<tuple<int, int, int>> p;
    for (int i = h-1; i >= 0; --i) {
        for (int j = w-1; j >= 0; --j) {
            if(v[i][j] == -1){
                v[i][j] = INF<int>;
                if(i != h-1) v[i][j] = min(v[i][j], v[i+1][j]+1);
                if(j != w-1) v[i][j] = min(v[i][j], v[i][j+1]+1);
                if(i != h-1 && j != w-1) v[i][j] = min(v[i][j], v[i+1][j+1]+1);
                v[i][j] = min({v[i][j], h-i, w-j});
            }
            p.emplace_back(v[i][j], i, j);
        }
    }
    sort(p.begin(),p.end(), greater<>());
    int q;
    cin >> q;
    vector<int> ans(q);
    vector<array<int, 4>> query(q);
    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d", &query[i][1], &query[i][2], &query[i][0]);
        query[i][3] = i;
    }
    array<int, 5> dy{0, -1, 1, 0, 0}, dx{0, 0, 0, -1, 1};
    auto f = [&](int i, int j, int k){
        int ii = i+dy[k], jj = j+dx[k];
        if(ii < 0 || h <= ii || jj < 0 || w <= jj) return -1;
        return ii*w+jj;
    };
    sort(query.begin(),query.end(), greater<>());
    int cur = 0;
    UnionFind uf(h*w);
    for (int i = 0; i < q; ++i) {
        while(cur < h*w && query[i][0] <= get<0>(p[cur])){
            int a, b, val; tie(val, a, b) = p[cur];
            for (int k = 1; k <= 4; ++k) {
                if(f(a, b, k) != -1 && v[a][b] <= v[a+dy[k]][b+dx[k]]){
                    uf.unite(f(a, b, k), f(a, b, 0));
                }
            }
            cur++;
        }
        ans[query[i][3]] = uf.size(f(query[i][1]-1, query[i][2]-1, 0));
    }
    for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}