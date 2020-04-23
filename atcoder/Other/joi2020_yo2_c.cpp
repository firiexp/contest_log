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
    vector<int> dp(n+1);
    int ans = 1;
    dp[n] = 1;
    for (int i = n-1; i >= 1; --i) {
        int ii = i, val = 0;
        while(ii){
            val += ii%10;
            ii /= 10;
        }
        if(i+val <= n) dp[i] = dp[i+val];
    }
    cout << accumulate(dp.begin(),dp.end(), 0) << "\n";
    return 0;
}