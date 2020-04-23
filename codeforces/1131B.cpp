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
    vector<int> as(n+1), bs(n+1);
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &as[i+1], &bs[i+1]);
        ans += max(0, min({as[i+1]-as[i]+1, bs[i+1]-bs[i]+1, as[i+1]-bs[i]+1, bs[i+1]-as[i]+1}) - (as[i] == bs[i]));
    }

    cout << ans << "\n";
    return 0;
}