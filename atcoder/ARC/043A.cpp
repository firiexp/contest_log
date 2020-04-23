#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <numeric>

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
    cout << setprecision(20);
    for (auto &&i : v) scanf("%lld", &i);
    auto p = minmax_element(v.begin(), v.end());
    ll x = *p.first, y = *p.second;
    long double avg = accumulate(v.begin(), v.end(), 0LL)*1.0/n;
    if(x == y && b != 0) {
        cout << -1 << "\n";
        return 0;
    }else if(x == y){
        cout << 0 << " " << 1.0*a-avg << "\n";
        return 0;
    }
    long double P = 1.0*b/(1.0*(y-x));
    cout << P << " " << 1.0*a-P*avg << "\n";
    return 0;
}
