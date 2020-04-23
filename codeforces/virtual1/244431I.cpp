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
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int l = 0, r = 0;
    int s = 0, ans = 0;
    while(l < n && r < n){
        while(r < n && s + v[r] <= t) s += v[r++];
        ans = max(ans, r-l);
        s -= v[l++];
        while(l > r && r < n) s += v[r++];
    }
    cout << ans << "\n";
    return 0;
}