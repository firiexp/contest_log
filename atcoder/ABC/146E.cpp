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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, k; // 長さはk未満
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i), i--;
    map<int, int> m;
    vector<int> S(n+1);
    for (int i = 0; i < n; ++i) {
        S[i+1] = (S[i]+v[i])%k;
    }
    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        if(m.count(S[i])) ans += m[S[i]];
        m[S[i]]++;
        if(i >= k-1){  // 長さはk未満
            m[S[i-k+1]]--;
        }
    }
    cout << ans << "\n";
    return 0;
}