#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

using P = pair<int, int>;

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
    vector<P> v(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[i] = make_pair(x-1, y-1);
    }
    int Q;
    cin >> Q;
    vector<P> q(Q), ran(Q);
    for (int i = 0; i < Q; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        q[i] = make_pair(x-1, y-1);
        ran[i] = make_pair(0, m);
    }
    for (int i = 0; i < 20; ++i) {
        vector<vector<int>> cand(m+1);
        for (int x = 0; x < Q; ++x) {
            cand[(ran[x].first+ran[x].second)/2].emplace_back(x);
        }
        UnionFind uf(n);
        for (int j = 0; j < m; ++j) {
            uf.unite(v[j].first, v[j].second);
            for (auto &&k : cand[j]) {
                if(uf.root(q[k].first) == uf.root(q[k].second)){
                    ran[k].second = j;
                }else {
                    ran[k].first = j+1;
                }
            }
        }
    }
    for (int i = 0; i < Q; ++i) {
        if(ran[i].first >= m) cout << -1 << "\n";
        else cout << ran[i].first+1 << "\n";
    }
    return 0;
}
