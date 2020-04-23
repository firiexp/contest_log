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

template <class F>
struct SparseTable {
    using T = typename F::T;
    vector<vector<T>> table;
    vector<int> u;
    SparseTable() = default;
    explicit SparseTable(const vector<T> &v){ build(v); }

    void build(const vector<T> &v){
        int n = v.size(), m = 1;
        while((1<<m) <= n) m++;
        table.assign(m, vector<T>(n));
        u.assign(n+1, 0);
        for (int i = 2; i <= n; ++i) {
            u[i] = u[i>>1] + 1;
        }
        for (int i = 0; i < n; ++i) {
            table[0][i] = v[i];
        }
        for (int i = 1; i < m; ++i) {
            int x = (1<<(i-1));
            for (int j = 0; j < n; ++j) {
                table[i][j] = F::f(table[i-1][j], table[i-1][min(j+x, n-1)]);
            }
        }
    }

    T query(int a, int b){
        int l = b-a;
        return F::f(table[u[l]][a], table[u[l]][b-(1<<u[l])]);
    }
};

struct Monoid{
    using T = int;
    static T f(T a, T b) { return max(a, b); }
    static T e() { return INF<int>; }
};
int main() {
    int n;
    cin >> n;
    vector<int> v(3*n);
    vector<pair<int, int>> u;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        v[i+n] = v[i+n+n] = v[i];
    }
    vector<int> ans(3*n, INF<int>);
    SparseTable<Monoid> A(v);
    for (int i = 0; i < n; ++i) {
        int cur = i+2*n;
        int ok = -1, ng = cur;
        while(ng - ok > 1){
            int mid = (ok+ng)/2;
            (A.query(mid, cur) > 2*v[cur] ? ok : ng) = mid;
        }
        if(ok != -1){
            ans[ok] = min(ans[ok], cur-ok);
        }
    }
    for (int i = 3*n-1; i >= 1; --i) {
        ans[i-1] = min(ans[i-1], ans[i]+1);
    }
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        int a = min({ans[i], ans[i+n], ans[i+2*n]});
        if(a == INF<int>) printf("-1");
        else printf("%d", a);
    }
    puts("");
    return 0;
}