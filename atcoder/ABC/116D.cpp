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

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) {
        int t, d;
        scanf("%d %d", &t, &d);
        v[t-1].emplace_back(d);
    }
    for (int i = 0; i < n; ++i) {
        sort(v[i].begin(), v[i].end(),greater<>());
    }
    vector<ll> a, b;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            if(j == 0) a.emplace_back(v[i][j]);
            else b.emplace_back(v[i][j]);
        }
    }
    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());
    vector<ll> A(n+1,0), B(n+1,0);
    for (int i = 0; i < n; ++i) {
        A[i+1] = A[i]+(i < a.size() ? a[i] : 0);
    }
    for (int i = 0; i < n; ++i) {
        B[i+1] = B[i]+(i < b.size() ? b[i] : 0);
    }
    ll ans = 0;
    for (ll i = 1; i <= min((int)a.size(), k); ++i) {
        ans = max(ans, A[i]+B[k-i]+i*i);
    }
    cout << ans << "\n";
    return 0;
}
