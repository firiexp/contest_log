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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> dp1(n, 1), dp2(n, 1);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(v[j] < v[i]) dp1[i] = max(dp1[i], dp2[j]+1);
            if(v[i] < v[j]) dp2[i] = max(dp2[i], dp1[j]+1);
        }
        ans = max({ans, dp1[i], dp2[i]});
    }
    cout << (ans < 3 ? 0 : ans) << "\n";
    return 0;
}