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
    cin >> n;
    vector<ll> v;
    ll p = 1;
    for (int i = 0; i <= n; ++i) {
        ll q = 1;
        for (int j = 0; j <= n; ++j) {
            v.emplace_back(p*q);
            q *= 5;
        }
        p *= 2;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto &&i : v) {
        cout << i << "\n";
    }
    return 0;
}
