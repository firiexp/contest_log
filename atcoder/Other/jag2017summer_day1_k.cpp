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

static const int MOD = 998244353;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    ll S = 0;
    for (int i = 0; i < n; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        S += b;
        v[i] = a+b;
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        S -= v[i];
        if(S >= 0) ans++;
    }
    cout << ans << "\n";
    return 0;
}