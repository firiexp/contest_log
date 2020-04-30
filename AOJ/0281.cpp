#include <iostream>
#include <algorithm>
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
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = min({a, b, c});
        a -= ans; b -= ans; c -= ans;
        int ans2 = min(a/2, b);
        a -= ans2*2; b -= ans2;
        cout << ans+ans2+a/3 << "\n";
    }
    return 0;
}