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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }
int main() {
    int n;
    cin >> n;
    array<ll, 100002> ar{}, dp{};
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ar[x]++;
    }
    dp[1] = ar[1];
    for (ll i = 2; i < 100002; ++i) {
        dp[i] = max(dp[i-1], dp[i-2]+i*ar[i]);
    }
    cout << dp[100001] << "\n";
    return 0;
}
