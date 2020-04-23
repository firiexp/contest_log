#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INXF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll n;
    cin >> n;
    map<int, ll> m;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i), m[i]++;
    ll ans = 0;
    for (auto &&i : m) {
        for (auto &&j : m) {
            if(i == j) continue;
            for (auto &&k : m) {
                if(j == k || i == k) continue;
                ans += i.second*j.second*k.second;
            }
        }
    }
    cout << (ans/6)%MOD << "\n";
    return 0;
}
