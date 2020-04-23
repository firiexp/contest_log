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

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> a(n);
    iota(a.begin(),a.end(), 0);
    sort(a.begin(),a.end(), [&](int x, int y){ return v[x] > v[y]; });
    vector<int> val(n);
    ll ans2 = 0;
    for (int i = 0; i < n; ++i) {
        if(i < m*k) val[a[i]] = 1, ans2 += v[a[i]];
        else val[a[i]] = 0;
    }
    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        cnt += val[i];
        if(val[i] && cnt%m == 0) ans.emplace_back(i+1);
    }
    cout << ans2 << "\n";
    for (int i = 0; i < k-1; ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}