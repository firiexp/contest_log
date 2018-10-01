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
    int n;
    string s, t, u;
    cin >> n >> s >> t;
    for (int i = 0; i < n; ++i) {
        if(s[i] == t[i]) u += "A";
        else {
            u += "B";
            ++i;
        }
    }
    ll x;
    x = (u[0] == 'A' ? 3LL : 6LL);
    for (int i = 1; i < u.length(); ++i) {
        if(u[i-1] == 'A' && u[i] == 'A') x = x * 2 % MOD;
        if(u[i-1] == 'A' && u[i] == 'B') x = x * 2 % MOD;
        if(u[i-1] == 'B' && u[i] == 'B') x = x * 3 % MOD;
    }
    cout << x << "\n";
    return 0;
}
