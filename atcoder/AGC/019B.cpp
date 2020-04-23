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
    string s;
    cin >> s;
    ll ans = s.length()*(s.length()-1)/2 + 1;
    map<char, ll> m;
    for (auto &&i : s) {
        m[i]++;
    }
    for (auto &&i : m) {
        ans -= i.second*(i.second-1)/2;
    }
    cout << ans << "\n";
    return 0;
}
