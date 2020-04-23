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


template<class T>
vector<T> prime_factor(T n){
    vector<T> res;
    for(ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res.emplace_back(i);
            n /= i;
        }
    }
    if(n != 1) res.emplace_back(n);
    return res;
}

int main() {
    int n, d;
    cin >> n >> d;
    if(d == 1){
        cout << (ll)n*(n+1)/2 << "\n";
        return 0;
    }
    auto p = prime_factor(d);
    auto q = p;
    sort(q.begin(), q.end());
    q.erase(unique(q.begin(), q.end()), q.end());
    int m = q.size();
    vector<int> x(m);
    for (auto &&i : p) {
        for (int j = 0; j < q.size(); ++j) {
            if(i == q[j]) x[j]++;
        }
    }
    vector<int> v(n);
    for (auto &&k : v) scanf("%d", &k);
    vector<vector<int>> cnt(n, vector<int>(m, 0));
    vector<ll> u(n+1);
    for (int i = 0; i < n; ++i) u[i] = v[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            while(u[i]%q[j] == 0) u[i] /= q[j], cnt[i][j]++;
        }
    }
    vector<int> dp(n);
    int l = 0, r = 0;
    while(l < n){
        while(r < n && *max_element(x.begin(),x.end()) > 0){
            for (int i = 0; i < m; ++i) {
                x[i] -= cnt[r][i];
            }
            r++;
        }
        dp[l] = r + (*max_element(x.begin(),x.end()) > 0);
        for (int i = 0; i < m; ++i) {
            x[i] += cnt[l][i];
        }
        l++;
    }
    u[0] = 0;
    for (int i = 0; i < n; ++i) {
        u[i+1] = (u[i]+v[i])%d;
    }
    map<int, int> M;
    int cur = n;
    ll ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        while(cur >= dp[i]) M[u[cur--]]++;
        ans += M[u[i]];
    }
    cout << ans << "\n";
    return 0;
}