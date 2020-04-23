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

bool is_uruu(int n){ return (n%4 == 0) ^ (n%100 == 0) ^ (n%400 == 0); }

int main() {
    ll n;
    cin >> n;
    n -= 2014;
    ll ans = (n/400)*57; n %= 400;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        (k += 365 + (is_uruu(i+2015))) %= 7;
        if(k == 0) ans++;
    }
    cout << ans << "\n";
    return 0;
}