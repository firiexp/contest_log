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
    vector<pair<int, int>> v(n);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v[i] = {x, i};
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n-1; ++i) {
        ans[v[i].second] = v.back().first;
    }
    ans[v.back().second] = v[n-2].first;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}