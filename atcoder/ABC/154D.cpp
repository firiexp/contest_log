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
    int n, k;
    cin >> n >> k;
    vector<int> S(n+1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        S[i+1] = S[i]+x+1;
    }
    int ans = 0;
    for (int i = 0; i+k <= n; ++i) {
        ans = max(ans, S[i+k]-S[i]);
    }
    printf("%.10lf\n", ans/2.0);
    return 0;
}