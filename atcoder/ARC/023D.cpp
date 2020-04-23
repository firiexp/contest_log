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
    vector<int> v(n);
    for (auto &&k : v) scanf("%d", &k);

    map<int, ll> ans;
    vector<map<int, ll>> X(2);
    for (int i = 0; i < n; ++i) {
        int now = i&1, nxt = now^1;
        X[now].clear();
        for (auto &&j : X[nxt]) {
            X[now][__gcd(j.first, v[i])] += j.second;
        }
        X[now][v[i]]++;
        for (auto &&j : X[now]) {
            ans[j.first] += j.second;
        }

    }
    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        printf("%lld\n", ans[x]);
    }
    return 0;
}