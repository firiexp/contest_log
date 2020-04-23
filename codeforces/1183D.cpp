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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cnt[v[i]]++;
    }
    vector<int> a;
    a.reserve(cnt.size());
    for (auto &&j : cnt) {
        a.emplace_back(j.second);
    }
    sort(a.begin(),a.end(), greater<>());
    int ans = 0, val = INF<int>;
    for (int i = 0; i < a.size(); ++i) {
        ans += min(val-1, a[i]);
        val = max(1, min(val-1, a[i]));
    }
    printf("%d\n", ans);
}

int main() {
    int q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}