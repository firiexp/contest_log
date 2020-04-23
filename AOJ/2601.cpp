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
    vector<int> dp(n);
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        ans--;
        if(!v[i]) ans = INF<int>;
        else if(v[i] < 0){
            ans = min(ans, -v[i]);
        }else {
            dp[i] = max(dp[i], min(v[i], ans));
        }
    }
    ans = -1;
    for (int i = n-1; i >= 0; --i) {
        ans--;
        if(!v[i]) ans = INF<int>;
        else if(v[i] < 0){
            ans = min(ans, -v[i]);
        }else {
            dp[i] = max(dp[i], min(v[i], ans));
        }

    }
    cout << accumulate(dp.begin(),dp.end(), 0) << "\n";
    return 0;
}