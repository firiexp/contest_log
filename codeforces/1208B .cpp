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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int ans = n-1;
    map<int, int> m;
    int f = 0;
    for (int i = 0; i < n; ++i) {
        auto mm = m;
        for (int j = n - 1; j >= 0; --j) {
            ans = min(ans, j-i+1);
            mm[v[j]]++;
            if(mm[v[j]] > 1) break;
        }
        m[v[i]]++;
        if(m[v[i]] > 1) break;
    }
    cout << ans << "\n";
    return 0;
}