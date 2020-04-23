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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&j : v) scanf("%d", &j);
    ll ans = 0;
    sort(v.begin(),v.end());
    for (int i = 0; i < n/2; ++i) {
        ans += (v[i]+v[n-i-1])*(v[i]+v[n-i-1]);
    }
    cout << ans << "\n";
    return 0;
}