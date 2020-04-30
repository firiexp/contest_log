#include <iostream>
#include <algorithm>
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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int an = INF<int>;
    for (int i = 0; i <= v[0]; ++i) {
        auto a = v;
        a[0] -= i;
        int ans = i;
        for (int j = 0; j+1 < n; ++j) {
            ans += max(0, a[j])*2;
            a[j+1] -= max(0, a[j]);
        }
        ans += max(0, a.back());
        an = min(an, ans);
    }
    cout << an << "\n";
    return 0;
}