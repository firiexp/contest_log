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
    vector<int> dp1(n+1), dp2(n+1);
    for (int i = 0; i < n; ++i) {
        dp2[i+1] = max(dp1[i], dp2[i]);
        dp1[i+1] = dp2[i]+1;
        if(!i || v[i-1] == v[i]){
            dp1[i+1] = max(dp1[i+1], dp1[i]+1);
        }
    }
    cout << max(dp1.back(), dp2.back()) << "\n";
    return 0;
}