#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld",&i);
    sort(v.begin(), v.end(), greater<>());
    int l = MOD, r = 0;
    while (std::abs(r-l) > 1){
        int mid = (l+r)/2;
        ll p = 0;
        for (auto &&i : v) {
            if(i > mid*b) p += (i-mid*b+a-b-1)/(a-b);
        }
        if(p <= mid){
            l = mid;
        }else {
            r = mid;
        }
    }
    cout << l << "\n";
    return 0;
}
