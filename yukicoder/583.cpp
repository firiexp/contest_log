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
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<int> A(m), B(m);
    for (int i = 0; i < m; ++i) {
        cin >> A[i] >> B[i];
        uf.unite(A[i], B[i]);
    }
    vector<int> dp(n);
    for (int i = 0; i < m; ++i) {
        dp[uf.root(A[i])]++;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if(dp[i]) cnt++;
    }
    if(cnt > 1) {
        puts("NO");
        return 0;
    }
    cnt = 0;
    vector<int> deg(n);
    for (int i = 0; i < m; ++i) {
        deg[A[i]]++; deg[B[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        cnt += deg[i]%2;
    }
    if(cnt == 0 || cnt == 2) puts("YES");
    else puts("NO");
    return 0;
}