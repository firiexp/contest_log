#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

ll snuke(ll n){
    ll k = 0;
    for (auto &&i : to_string(n)) {
        k += i - '0';
    }
    return k;
}

ll f(ll n){
    ll ans = n+1;
    string s = to_string(ans);
    string t = s;
    for (int i = s.length()-1; i >= 0; --i) {
        while(t[i] != '9') {
            t[i]++;
            ll m = stoll(t), x = ans * snuke(m), y = m * snuke(ans);
            if (x > y) {
                ans = m;
            }
        }
    }
    return ans;
}
int main() {
    vector<ll> v{1};
    ll inf = 1000000000000001;
    ll x = 1;
    while(x < inf){
        x = f(x);
        v.emplace_back(x);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cout << v[i] << "\n";
    }
    return 0;
}
