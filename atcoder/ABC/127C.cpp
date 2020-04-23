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
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        v[l-1]++; v[r]--;
    }
    for (int i = 0; i < n; ++i) {
        v[i+1] += v[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i] == m) ans++;
    }
    cout << ans << "\n";
    return 0;
}