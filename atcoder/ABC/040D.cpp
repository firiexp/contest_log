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

    int size(int i){
        return -uni[i];
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> v(m);
    for (int i = 0; i < m; ++i) {
        int a, b, y;
        scanf("%d %d %d", &a, &b, &y);
        v[i] = make_tuple(y, a-1, b-1);
    }
    sort(v.begin(), v.end(), greater<>());
    int q;
    cin >> q;
    vector<tuple<int, int, int>> query(q);
    vector<int> ans(q);
    for (int i = 0; i < q; ++i) {
        int t, u;
        scanf("%d %d", &t, &u);
        query[i] = make_tuple(u, t-1, i);
    }
    sort(query.begin(), query.end(), greater<>());
    int cur = 0;
    UnionFind uni(n);
    for (int i = 0; i < q; ++i) {
        int u, t, w; tie(u, t, w) = query[i];
        while(cur < m && get<0>(v[cur]) > u) {
            uni.unite(get<1>(v[cur]),get<2>(v[cur]));
            cur++;
        }
        ans[w] = uni.size(i);
    }
    for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
