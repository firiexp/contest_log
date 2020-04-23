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
    int n;
    array<int, 4> di{0, 0, -1, 1}, dj{1, -1, 0, 0};
    while(cin >> n, n){
        map<pair<int, int>, int> s;
        int cnt = 1;
        for (int i = 0; i < n; ++i) {
            int x, y; char c;
            scanf("%d %d %c", &x, &y, &c);
            if(c == 'x'){
                s[{x, y}] = cnt;
                s[{x+1, y}] = cnt++;
            }else {
                s[{x, y}] = cnt;
                s[{x, y+1}] = cnt++;
            }
        }
        UnionFind uf(cnt*2);
        for (auto &&x : s) {
            int i, j; tie(i, j) = x.first;
            int p = x.second;
            for (int k = 0; k < 4; ++k) {
                if(s.count({i+di[k], j+dj[k]})) {
                    int q = s[{i+di[k], j+dj[k]}];
                    if(p == q) continue;
                    uf.unite(p, q+cnt);
                    uf.unite(q, p+cnt);
                }
            }
        }
        int ok = 1;
        for (int i = 1; i < cnt; ++i) {
            if(uf.same(i, i+cnt)){
                ok = 0;
                break;
            }
        }
        puts(ok ? "Yes" : "No");
    }
    return 0;
}