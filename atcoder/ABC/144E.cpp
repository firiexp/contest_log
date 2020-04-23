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
    ll n, k;
    cin >> n >> k;
    vector<int> a(n), f(n);
    for (auto &&i : a) scanf("%d", &i);
    for (auto &&i : f) scanf("%d", &i);
    sort(a.begin(),a.end());
    sort(f.begin(),f.end(), greater<>());
    ll ng = -1, ok = 1000000000001;
    while(ok-ng > 1){
        auto mid = (ok+ng)/2;
        ll s = 0;
        for (int i = 0; i < n; ++i) {
            s += max<ll>(0, a[i]-mid/f[i]);
        }
        (s > k ? ng : ok) = mid;
    }
    cout << ok << "\n";
    return 0;
}