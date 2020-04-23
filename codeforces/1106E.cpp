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
#include <assert.h>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    using P = pair<int, int>;
    vector<array<int, 4>> v(k);
    vector<pair<int, int>> Q;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < 4; ++j) {
            scanf("%d", &v[i][j]);
        }
        v[i][0]--;
        Q.emplace_back(v[i][0], i);
        Q.emplace_back(v[i][1], i);
    }
    vector<int> val(n), d(n);
    multiset<P> s;
    sort(Q.begin(),Q.end());
    vector<int> a(k);
    {
        int cur = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            while(cur < 2*k && Q[cur].first <= i){
                int x = Q[cur].second;
                auto p = s.find(make_pair(v[x][3], v[x][2]));
                if(a[x]){
                    s.erase(p);
                    a[x]--;
                    cnt--;
                }else {
                    s.insert(make_pair(v[x][3], v[x][2]));
                    a[x]++;
                    cnt++;
                }
                cur++;
            }
            if(s.empty()){
                val[i] = 0;
                d[i] = i+1;
            }else {
                auto x = *(--s.end());
                val[i] = x.first;
                d[i] = x.second;
            }
        }
    }
    auto dp = make_v(n+1, m+1, INF<ll>);
    for (int i = 0; i <= m; ++i) {
        dp[0][i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            chmin(dp[d[i]][j], dp[i][j]+val[i]);
            chmin(dp[i+1][j+1], dp[i][j]);
        }
        chmin(dp[d[i]][m], dp[i][m]+val[i]);
    }
    ll ans = INF<ll>;
    for (int i = 0; i <= m; ++i) {
        ans = min(ans, dp[n][i]);
    }
    assert(ans != INF<ll>);
    cout << ans << "\n";
    return 0;
}