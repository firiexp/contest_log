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

vector<ll> gauss_jordan(vector<ll> a, ll k){
    int n = a.size(), m = 64;
    int cnt = 0;
    vector<int> v;
    for (int i = 63; i >= 0; --i) {
        if(!((k & (1LL << i)))) v.emplace_back(i);
    }
    for (int i = 63; i >= 0; --i) {
        if(((k & (1LL << i)))) v.emplace_back(i);
    }
    for (int cur = 0; cur < 64 && cnt != n; ++cur) {
        int i = v[cur];
        int p = cnt;
        for (int j = cnt; j < n; ++j) {
            if(a[j] & (1LL << i)){
                p = j;
                break;
            }
        }
        if((a[p] & (1LL << i)) == 0) continue;
        swap(a[cnt], a[p]);
        for (int j = 0; j < n; ++j) {
            if(cnt == j) continue;
            if(a[j] & (1LL << i)) a[j] ^= a[cnt];
        }
        cnt++;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    ll X = 0;
    for (auto &&i : v) scanf("%lld", &i), X ^= i;
    ll ans = 0;
    auto p = gauss_jordan(v, X);
    for (int i = 0; i < n; ++i) {
        ans ^= p[i];
    }
    cout << ans + (ans ^ X) << "\n";
    return 0;
}