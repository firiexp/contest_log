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
#include <cassert>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*7+208;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> v(n);
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        v[i].resize(k);
        for (int j = 0; j < k; ++j) {
            int a;
            scanf("%d", &a);
            v[i][j].first = a;
        }
        for (int j = 0; j < k; ++j) {
            int a;
            scanf("%d", &a);
            v[i][j].second = a;
        }
    }
    vector<int> A(m);
    vector<ll> C(m);
    int q;
    cin >> q;
    m = 0;
    for (int i = 0; i < q; ++i) {
        int id, mul;
        scanf("%d %d", &id, &mul);
        for (auto &&j : v[id-1]) {
            A[m] = j.first;
            C[m] = (ll)j.second*mul;
            m++;
        }
    }
    vector<int> l(m), r(m);
    {
        stack<pair<int, int>> Q;
        for (int i = 0; i < m; ++i) {
            int lb = max(0, i-A[i]+1);
            while(!Q.empty() && Q.top().second >= lb){
                lb = min(lb, Q.top().first);
                Q.pop();
            }
            l[i] = lb;
            Q.emplace(l[i], i);
        }
        while(!Q.empty()) Q.pop();
        for (int i = m-1; i >= 0; --i) {
            int rb = min(m-1, i+A[i]-1);
            while(!Q.empty() && Q.top().second <= rb){
                rb = max(rb, Q.top().first);
                Q.pop();
            }
            r[i] = rb;
            Q.emplace(r[i], i);
        }
        while(!Q.empty()) Q.pop();
    }
    vector<ll> dp(m+1, INF<ll>);
    dp[0] = 0;
    deque<pair<int, ll>> Q;
    for (int i = 0; i < m; ++i) {
        dp[i+1] = dp[l[i]]+C[i];
        while(!Q.empty() && Q.back().first < i) Q.pop_back();
        if(!Q.empty()) dp[i+1] = min(dp[i+1], Q.back().second);
        if (Q.empty() || Q.back().second >= dp[i]+C[i]) Q.emplace_back(r[i], dp[i]+C[i]);
    }
    cout << dp.back() << "\n";
    return 0;
}