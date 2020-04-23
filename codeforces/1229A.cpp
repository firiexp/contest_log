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
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &&i : a) scanf("%lld", &i);
    for (auto &&j : b) scanf("%lld", &j);
    ll ans = accumulate(b.begin(),b.end(), 0LL);
    vector<vector<int>> G(n);
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == j) continue;
            if(a[i]^(a[i]&a[j])){
                G[j].emplace_back(i);
                cnt[i]++;
            }
        }
    }
    int cur = n-1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(cnt[j] == cur){
                cur--;
                ans -= b[j];
                for (auto &&k : G[j]) {
                    cnt[k]--;
                }
            }
        }
    }
    if(cur < 0) ans = 0;
    cout << ans << "\n";
    return 0;
}