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
    ll n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    ll u = __gcd(n, m);
    for (int i = 0; i < u; ++i) {
        if(s[n/u*i] != t[m/u*i]){
            cout << "-1\n";
            return 0;
        }
    }
    cout << n*m / u << "\n";
    return 0;
}
