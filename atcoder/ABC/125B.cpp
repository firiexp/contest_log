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

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &&i : a) scanf("%d", &i);
    for (auto &&j : b) scanf("%d", &j);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(a[i] > b[i]) ans += a[i]-b[i];
    }
    cout << ans << "\n";
    return 0;
}