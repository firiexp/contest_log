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
    int w, h;
    while(cin >> w >> h, w){
        vector<int> ys{0, h-1}, xs{0, w-1};
        int n;
        cin >> n;
        vector<array<int, 4>> q(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                cin >> q[i][j*2] >> q[i][j*2+1];
                xs.emplace_back(q[i][j*2]);
                ys.emplace_back(q[i][j*2+1]);
            }
        }
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        auto zy = [&ys](int y){ return lower_bound(ys.begin(),ys.end(), y) - ys.begin(); };
        auto zx = [&xs](int x){ return lower_bound(xs.begin(),xs.end(), x) - xs.begin(); };
        h = ys.size(); w = xs.size();
        vector<vector<int>> v(h, vector<int>(w, 0));
        for (int i = 0; i < n; ++i) {
            int x1 = zx(q[i][0]), y1 = zy(q[i][1]),
                    x2 = zx(q[i][2]), y2 = zy(q[i][3]);
            v[y1][x1]++; v[y1][x2]--; v[y2][x1]--; v[y2][x2]++;
        }
        for (int i = 1; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                v[i][j] += v[i-1][j];
            }
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 1; j < w; ++j) {
                v[i][j] += v[i][j-1];
            }
        }
        h--; w--;
        UnionFind uf(h*w);
        array<int, 4> dy{-1, 1, 0, 0}, dx{0, 0, -1, 1};
        int cnt = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if(v[i][j]) continue;
                cnt++;
                for (int k = 0; k < 4; ++k) {
                    if(0 <= i+dy[k] && i+dy[k] < h && 0 <= j+dx[k] && j+dx[k] < w && !v[i+dy[k]][j+dx[k]]){
                        if(uf.unite(i*w+j, (i+dy[k])*w+(j+dx[k]))) cnt--;
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}