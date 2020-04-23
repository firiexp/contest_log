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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(n);
    vector<vector<int>> G(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        if(a > b) swap(a, b);
        G[a].emplace_back(b);
        A[a]++;
        B[b]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (ll)A[i]*B[i];
    }
    int q;
    cin >> q;
    printf("%lld\n", ans);
    for (int i = 0; i < q; ++i) {
        int x;
        scanf("%d", &x);
        x--;
        ans -= (ll)A[x]*B[x];
        B[x] += A[x];
        A[x] = 0;
        for (auto &&j : G[x]) {
            G[j].emplace_back(x);
            ans += B[j]-A[j]-1;
            B[j]--; A[j]++;
        }
        G[x].clear();
        printf("%lld\n", ans);
    }
    return 0;
}