#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

class UnionFind {
    int n;
public:
    vector<int> uni;
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

    int size(int i){
        return -uni[root(i)];
    }
};



int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &v[i].first, &v[i].second);
        v[i].first--; v[i].second--;
    }
    int q;
    cin >> q;
    vector<int> x(q), y(q), z(q);
    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d", &x[i], &y[i], &z[i]);
        x[i]--; y[i]--;
    }
    vector<int> ng(q, -1), ok(q, m);
    for (int i = 0; i < 30; ++i) {
        vector<pair<int, int>> mid;
        mid.reserve(q+1);
        for (int j = 0; j < q; ++j) {
            mid.emplace_back((ok[j]+ng[j])/2, j);
        }
        mid.emplace_back(INF<int>, -1);
        sort(mid.begin(), mid.end());
        UnionFind uf(n);
        int cur = 0;
        for (int j = 0; j < m; ++j) {
            uf.unite(v[j].first, v[j].second);
            while(mid[cur].first == j){
                int k = mid[cur].second;
                int c = uf.size(x[k])+(uf.root(x[k]) == uf.root(y[k]) ? 0 : uf.size(y[k]));
                if(c < z[k]) ng[k] = mid[cur].first;
                else ok[k] = mid[cur].first;
                cur++;
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        cout << ok[i]+1 << "\n";
    }
    return 0;
}
