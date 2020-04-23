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
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> v(n), u(m);
    for (auto &&i : v) scanf("%d", &i);
    for (auto &&j : u) scanf("%d", &j);
    sort(v.begin(),v.end());
    sort(u.begin(),u.end());
    int a = v.front(), b = u.back();
    int ans = r;
    ans = max(ans, r/a*b+r%a);
    cout << ans << "\n";
    return 0;
}