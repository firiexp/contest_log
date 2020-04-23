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
    vector<int> v(n-1);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> ans(n);
    ans[0] = v[0]; ans[n-1] = v[n-2];
    for (int i = 1; i < n-1; ++i) {
        ans[i] = min(v[i-1], v[i]);
    }
    cout << accumulate(ans.begin(),ans.end(), 0) << "\n";
    return 0;
}