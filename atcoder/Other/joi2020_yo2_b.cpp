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
    vector<pair<int, int>> v(n);
    for (auto &&i : v) scanf("%d %d", &i.first, &i.second);
    sort(v.begin(),v.end(), greater<>());
    int ans = 2*v[0].first;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, v[i].first+v[i].second);
    }
    cout << ans << "\n";
    return 0;
}