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
    vector<int> a(n), b(n), c(n-1);
    for (auto &&i : a) scanf("%d", &i);
    for (auto &&j : b) scanf("%d", &j);
    for (auto &&k : c) scanf("%d", &k);
    ll ans = accumulate(b.begin(),b.end(), 0LL);
    for (int i = 0; i < n-1; ++i) {
        if(a[i+1]-a[i] == 1) ans += c[a[i]-1];
    }
    cout << ans << "\n";
    return 0;
}