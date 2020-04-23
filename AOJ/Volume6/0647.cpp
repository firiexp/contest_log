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
using ll = int64_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int ans = v[n-1]-v[0]+1;
    vector<int> u(n-1);
    for (int i = 0; i < n - 1; ++i) {
        u[i] = v[i+1]-v[i]-1;
    }
    sort(u.begin(), u.end(), greater<>());
    for (int i = 0; i < k - 1; ++i) {
        ans -= u[i];
    }
    cout << ans << "\n";
    return 0;
}
