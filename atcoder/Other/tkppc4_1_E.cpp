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
    int n, m, k, e;
    cin >> n >> m >> k >> e;
    vector<int> a(n), b(m);
    for (auto &&i : a) scanf("%d", &i);
    for (auto &&j : b) scanf("%d", &j);
    sort(a.begin(),a.end(), greater<>());
    sort(b.begin(),b.end(), greater<>());
    ll s = accumulate(a.begin(),a.end(), 0LL);
    ll t = accumulate(b.begin(),b.begin()+k, 0LL)+e;
    if(s <= t){
        puts("Yes");
        int ans = k;
        for (int i = k-1; i >= 0; --i) {
            t -= b[i];
            if(s <= t) ans = min(ans, i);
        }
        cout << ans << "\n";
    }else {
        puts("No");
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            s -= a[i];
            if(s <= t) ans = max(ans, n-i-1);
        }
        cout << ans << "\n";
    }
    return 0;
}