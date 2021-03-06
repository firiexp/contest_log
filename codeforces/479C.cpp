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
    for (auto &&i : v) {
        scanf("%d %d", &i.first, &i.second);
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(ans <= v[i].second) ans = v[i].second;
        else ans = v[i].first;
    }
    cout << ans << "\n";
    return 0;
}