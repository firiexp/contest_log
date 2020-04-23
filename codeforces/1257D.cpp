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


struct F {
    using T = int;
    static T f(T a, T b) { return max(a, b); }
    static T e() { return INF<int>; }
};
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &&i : v) scanf("%d", &i);
        int m;
        cin >> m;
        vector<pair<int, int>> u(m);
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &u[i].second, &u[i].first); // (s, p)
        }
        sort(u.begin(),u.end());
        vector<int> val(n+1, 0);
        val[0] = INF<int>;
        SparseTable<F> table(v);
        int cur = m-1;
        for (int j = n; j >= 1; --j) {
            if(j != n) val[j] = max(val[j], val[j+1]);
            while(cur >= 0 && u[cur].first >= j){
                val[j] = max(val[j], u[cur].second);
                cur--;
            }
        }
        int ans = 0; cur = 0;
        while(cur < n){
            ans++;
            int ok = cur, ng = n+1;
            while(ng-ok > 1){
                int mid = (ok+ng)/2;
                if(table.query(cur, mid) <= val[mid-cur]) ok = mid;
                else ng = mid;
            }
            if(ok == cur) {
                ans = -1;
                break;
            }
            cur = ok;
        }
        printf("%d\n", ans);
    }
    return 0;
}