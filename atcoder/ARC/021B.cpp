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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> ans(n, 0);
    for (int i = 1; i < n; ++i) {
        ans[i] = ans[i-1]^v[i-1];
    }
    for (int i = 0; i < n; ++i) {
        if((ans[i]^ans[(i+1)%n]) != v[i]) {
            puts("-1");
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}
