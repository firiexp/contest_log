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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

void solve(){
    int n;
    scanf("%d", &n);
    map<int, int> cnt, cnt2;
    for (int i = 0; i < n; ++i) {
        int a, f;
        scanf("%d %d", &a, &f);
        cnt[a]++;
        cnt2[a] += f;
    }
    vector<pair<int, int>> a;
    a.reserve(cnt.size());
    for (auto &&j : cnt) {
        a.emplace_back(j.second, cnt2[j.first]);
    }
    sort(a.begin(),a.end(), greater<>());
    int ans = 0, val = INF<int>;
    vector<int> x;
    for (auto & i : a) {
        ans += min(val-1, i.first);
        x.emplace_back(min(val-1, i.first));
        val = max(1, min(val-1, i.first));
    }
    int cur = 0, ans2 = 0;
    priority_queue<int> Q;
    for (auto &&k : x) {
        while(cur < a.size() && a[cur].first >= k){
            Q.emplace(a[cur].second);
            cur++;
        }
        ans2 += min(k, Q.top()); Q.pop();
    }
    printf("%d %d\n", ans, ans2);
}

int main() {
    int q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}