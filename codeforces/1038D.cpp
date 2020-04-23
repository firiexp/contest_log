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
    int n;
    cin >> n;
    if(n == 1){
        int x;
        scanf("%d", &x);
        printf("%d\n", x);
        return 0;
    }
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    sort(v.begin(),v.end());
    ll ans = 0;
    if(v.front() >= 0){
        for (int i = 0; i < n; ++i) {
            if(i) ans += v[i];
            else ans -= v[i];
        }
    }else if(v.back() <= 0){
        for (int i = 0; i < n; ++i) {
            if(i != n-1) ans -= v[i];
            else ans += v[i];
        }
    }else {
        for (int i = 0; i < n; ++i) {
            ans += abs(v[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}