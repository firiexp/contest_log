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
    reverse(v.begin(), v.end());
    int ans = n;
    for (int i = 0; i < n; ++i) {
        if(v[i] == ans) ans--;
    }
    cout << ans << "\n";
    return 0;
}
