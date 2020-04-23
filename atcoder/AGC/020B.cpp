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
    ll la = 2, ra = 2;
    int k;
    cin >> k;
    vector<ll> v(k);
    for (auto &&i : v) scanf("%lld", &i);
    for (int i = k-1; i >= 0; --i) {
        ll q = ra/v[i]*v[i], p = (la+v[i]-1)/v[i]*v[i];
        if((p < la || ra < p)&&(q < la || ra < q)){
            puts("-1");
            return 0;
        }
        la = p, ra = q+v[i]-1;
    }
    cout << la << " " << ra << "\n";
    return 0;
}
