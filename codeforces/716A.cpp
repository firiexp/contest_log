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
    int n, c;
    cin >> n >> c;
    vector<int> v(n);
    for (auto &&j : v) scanf("%d", &j);
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if(v[i]-v[i-1] > c) ans = 1;
        else ans++;
    }
    cout << ans << "\n";
    return 0;
}