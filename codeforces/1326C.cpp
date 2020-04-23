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

static const int MOD = 998244353;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> cnt;
    ll ans0 = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i] > n-k) {
            cnt.emplace_back(i);
            ans0 += v[i];
        }
    }

    ll ans = 1;
    for (int i = 0; i < k-1; ++i) {
        ans = ans*(cnt[i+1]-cnt[i])%MOD;
    }
    printf("%lld %lld\n", ans0, ans);
    return 0;
}